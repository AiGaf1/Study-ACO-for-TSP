#include <cfloat>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;
typedef struct Point {
	int index;
	double x;
	double y;
}Point;

const int MAX_POINT_NUM = 150;

void clearAllowed(bool* allowed, int cityNum)
{
	for (int i = 1; i <= cityNum; i++) {
		allowed[i] = true;
	}
}

int calcProbabAndSel(const double Tau[][MAX_POINT_NUM], const double heuristVal[][MAX_POINT_NUM],
	bool allowed[], int currCityIndex, int cityNum, double alpha, double beta, default_random_engine& randEngine)
{
	map <int, double> probab;

	double denominSum = 0;
	for (int s = 1; s <= cityNum; s++) {
		if (allowed[s] == true) {
			double val = pow(Tau[currCityIndex][s], alpha) * pow(heuristVal[currCityIndex][s], beta);
			probab.insert({ s,val });
			denominSum += val;
		}
	}

	int selectedCityIndex = -1;
	if (probab.size() == 1) {
		//means we have no city for choosing
		selectedCityIndex = probab.begin()->first;
	}
	else {
		double sumSelect = 0;

		uniform_real_distribution<double> randDistribut(0, 1);
		double generatedProbab = randDistribut(randEngine);

		for (auto& r : probab) {
			r.second = r.second / denominSum;
			sumSelect += r.second;
			if (sumSelect >= generatedProbab) {
				selectedCityIndex = r.first;
				break;
			}
		}
		selectedCityIndex = selectedCityIndex == -1 ? (--probab.end())->first : selectedCityIndex;
	}

	allowed[selectedCityIndex] = false;

	return selectedCityIndex;
}

void calculateDeltaTauPerAnt(double deltaTau[][MAX_POINT_NUM], int Q, ::vector<int>& path, double antPathLength)
{
	for (int k = 0, pathLength = path.size() - 1; k < pathLength; k++) {
		int i = path[k];
		int j = path[k + 1];
		deltaTau[i][j] = deltaTau[j][i] += Q / antPathLength;
	}
}

void constructPath(const double graphMatrix[][MAX_POINT_NUM], const double Tau[][MAX_POINT_NUM], const double heuristVal[][MAX_POINT_NUM],
	vector<int>& path, double& currDist, int cityNum, double alpha, double beta, default_random_engine& randEngine, uniform_int_distribution<int>& randDistribut)
{
	bool allowed[MAX_POINT_NUM];
	clearAllowed(allowed, cityNum);

	int startNum = randDistribut(randEngine);
	path.push_back(startNum);
	allowed[startNum] = false;

	int current = startNum;
	while (path.size() < cityNum) {
		int next = calcProbabAndSel(Tau, heuristVal, allowed, current, cityNum, alpha, beta, randEngine);

		//add it to path and update distance
		path.push_back(next);
		currDist += graphMatrix[current][next];

		current = next;
	}

	currDist += graphMatrix[current][startNum];
}

void updateTau(double Tau[][MAX_POINT_NUM], double deltaTauTotal[][MAX_POINT_NUM], double rho, int cityNum)
{
	for (int i = 1; i <= cityNum; i++) {
		for (int j = 1; j <= cityNum; j++) {
			double val = (1.0 - rho) * Tau[i][j] + deltaTauTotal[i][j];
			Tau[i][j] = val;
		}
	}
}
double start(double new_alpha, double new_beta) {

	ifstream in("tsp/eil76.txt");
	if (!in.is_open()) {
		cout << "No exist!" << ::endl;
	}

	vector<Point> points;
	int index;
	double x, y;
	int cityNum = 0;
	while (in >> index >> x >> y) {
		points.push_back({ index,x,y });
	}

	double graphMatrix[MAX_POINT_NUM][MAX_POINT_NUM];
	double heuristVal[MAX_POINT_NUM][MAX_POINT_NUM];

	for (auto& p : points) {
		cityNum++;
		for (auto& pr : points) {
			if (p.index != pr.index) {
				double val = sqrt((p.x - pr.x) * (p.x - pr.x) + (p.y - pr.y) * (p.y - pr.y));
				graphMatrix[p.index][pr.index] = graphMatrix[pr.index][p.index] = val;
				heuristVal[p.index][pr.index] = heuristVal[pr.index][p.index] = 1 / val;
			}
			else {
				graphMatrix[p.index][pr.index] = graphMatrix[pr.index][p.index] = 0;
				heuristVal[p.index][pr.index] = heuristVal[pr.index][p.index] = 0;
			}
		}
	}

	const int antNum = 76;
	const int iterTimes = 300;
	double alpha = new_alpha;
	double beta = new_beta;
	double rho = 0.3;
	int left = 2;
	int Q = 1;
	double Tau[MAX_POINT_NUM][MAX_POINT_NUM];
	vector<int> bestPath(cityNum);
	double bestLength = DBL_MAX;

	for (int i = 1; i <= cityNum; i++) {
		for (int j = 1; j <= cityNum; j++) {
			Tau[i][j] = 1;
		}
	}

	default_random_engine randEngine;
	uniform_int_distribution<int> randDistribut(1, cityNum);

	int iterCounter = 0;
	while (iterCounter < iterTimes) {
		double deltaTauTotal[MAX_POINT_NUM][MAX_POINT_NUM];
		for (int i = 1; i <= cityNum; i++) {
			for (int j = 1; j <= cityNum; j++) {
				deltaTauTotal[i][j] = 0;
			}
		}

		for (int i = 0; i < antNum; i++) {
						
			vector<int> path;
			double currDist = 0;
			constructPath(graphMatrix, Tau, heuristVal, path, currDist, cityNum, alpha, beta, randEngine, randDistribut);
						
			calculateDeltaTauPerAnt(deltaTauTotal, Q, path, currDist);
			
			if (currDist < bestLength) {
				bestLength = currDist;
				copy(path.cbegin(), path.cend(), bestPath.begin());
			}
		}
		updateTau(Tau, deltaTauTotal, rho, cityNum);

		iterCounter++;
	}
	/*for (auto& p : bestPath) {
		::cout << p << ' ';
	}*/
	return bestLength;
}

int main()
{
	double lenght;
	ofstream fout("eli76answers1.txt");

	for (double alpha = 0.2; alpha < 8; alpha += 0.2) {
		for (double beta = 0.2; beta < 8; beta += 0.2) {
			cout << "alpha = " << alpha << ", beta = " << beta << ", ";
			fout << "alpha = " << alpha << ", beta = " << beta << ", ";
			lenght = start(alpha,beta);
			cout << lenght << endl;
			fout << lenght << endl;
		}
	}

	system("pause");
	
	return 0;
}