from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
import matplotlib.pyplot as plt
from matplotlib.mlab import griddata
import numpy as np

data = np.genfromtxt("Data/eli76length.txt")

fig = plt.figure()
ax = fig.gca(projection='3d')

x = data[:,0]
y = data[:,1]
z = data[:,2]

xi = np.linspace(min(x), max(x), 322)
yi = np.linspace(min(y), max(y), 322)

X, Y = np.meshgrid(xi, yi)
Z = griddata(x, y, z, xi, yi, interp='linear')

ax.set_xlabel('$alpha$', fontsize = 20)
ax.set_ylabel('$beta$', fontsize = 20)
ax.set_zlabel('$lenght$', fontsize = 20)
ax.set_title('', fontsize = 18)
plt.tick_params(axis='x', labelsize=16)
plt.tick_params(axis='y', labelsize=16)
plt.tick_params(axis='z', labelsize=16)


surf = ax.plot_surface(X, Y, Z, rstride=10, cstride=10,vmin=min(z) + 5, vmax=566, cmap = cm.Spectral, linewidth=1, antialiased=True)

startz, endz = ax.get_zlim()
startx, endx = ax.get_xlim()
ax.set_zlim3d(startz, endz)
ax.set_xlim3d(startx, endx)
ax.set_ylim3d(0.2, 8)

ax.xaxis.set_ticks(np.arange(0.5, 5, 0.5))

fig.tight_layout()
fig.colorbar(surf)
plt.show()

