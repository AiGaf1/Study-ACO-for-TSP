import pandas as pd 
import numpy as np
import matplotlib.pyplot as plt


# data = np.genfromtxt('/home/aigaf/Desktop/Research/berlin52length.txt')
# df = pd.DataFrame(data)
# df.columns = ['alpha', 'beta', 'lenght']

# dfBerlin52 = df
# dfBerlin52 = df.groupby(['beta']).size().reset_index(name='perc')
# dfBerlin52['perc'] = 100 * dfBerlin52['perc']/886

# print(dfBerlin52)


Eil52 = np.genfromtxt('/home/aigaf/Desktop/Research/betaEil76.txt')
dfEil52 = pd.DataFrame(Eil52)
dfEil52.columns = ['alpha', 'beta', 'lenght']
dfEil52 = dfEil52.groupby(['beta']).size().reset_index(name='perc')
dfEil52['perc'] = 100*dfEil52['perc'] / 58

print(dfEil52)

# Eil76 = np.genfromtxt('/home/aigaf/Desktop/Research/betaEil76.txt')
# dfEil76 = pd.DataFrame(Eil76)
# dfEil76.columns = ['alpha', 'beta', 'lenght']
# dfEil76 = dfEil76.groupby(['beta']).size().reset_index(name='perc')
# dfEil76['perc'] = 100*dfEil76['perc'] / 65
# data = np.genfromtxt('/home/aigaf/Desktop/Research/berlin52length.txt')
# df = pd.DataFrame(data)
# df.columns = ['alpha', 'beta', 'lenght']

# dfBerlin52 = df
# dfBerlin52 = df.groupby(['beta']).size().reset_index(name='perc')
# dfBerlin52['perc'] = 100 * dfBerlin52['perc']/886

# print(dfBerlin52)

# print(dfEil76)
 


