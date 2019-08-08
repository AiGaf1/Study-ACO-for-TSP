# Study-ACO-for-TSP
Study of the effectiveness of the parameters of the ant colony optimization(ACO) for travel salesman problem(TSP)

The best performance of ant colony optimization (ACO) largely depends on the appropriate settings; therefore, their choice of ACO is important. In this repository, we will study the dependence of the quality of the task solution of the traveling salesman problem from the values of the algorithm parameters α and β.

  
![Alt text](https://github.com/AiGaf1/Study-ACO-for-TSP/blob/master/Research/Eil51.png)
  a) Problem Eil51

  
![Alt text](https://github.com/AiGaf1/Study-ACO-for-TSP/blob/master/Research/berlin52.png)
  b) Probmlem Berlin52
  
  
![Alt text](https://github.com/AiGaf1/Study-ACO-for-TSP/blob/master/Research/eil76.png)
  c) Problem Eil76
  Fig. 1 Graphs of the dependence of the objective function with respect to α, β for berlin ”,“ eli51 ”and“ eli76 ”.
                                  (a - “berlin”, b - “eli51”, c - “eli76”).
  
The initial of three-dimensional graphs ( can be concluded that the parameter is on the interval [0.4, 1.4]. The percentage of the best results for each parameter α in the above interval (Fig. 1).

F is the ratio of the number of successful program launches to the total
For a successful launch, it was taken to achieve any optimum of tasks within the average deviation of 2-3% for each task


![Alt text](https://github.com/AiGaf1/Study-ACO-for-TSP/blob/master/Research/diagram.png)
  Fig. 2 The dependence of the percentage of successful launches on the parameter α 

The histogram (Fig. 3) shows that the greatest number of successful starts for different tasks is achieved with α equal to 1.0.
Consider the parameter β with α equal to 1.0 for all problems.

![Alt text](https://github.com/AiGaf1/Study-ACO-for-TSP/blob/master/Research/diagram1.png)
  Fig. 3 The dependence of the percentage of successful launches on parameter β
  
  According to (Fig. 3) you can see that the histogram starts with 1.4. This means that less than β equal to 1.4 successful starts were not found. You can also see that the number of successful launches was the largest in the interval [2.8, 5].
 
