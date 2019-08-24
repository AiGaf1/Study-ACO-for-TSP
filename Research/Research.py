from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
import matplotlib.pyplot as plt
from matplotlib.mlab import griddata
import numpy as np

data = np.genfromtxt("/home/aigaf/Desktop/Research/eil51length.txt")



x = data[:,0]
y = data[:,1]
z = data[:,2]
j = 0
for i in range(886):
    if z[i] < 453 and y[i] < 8.0:
        print(x[i], y[i], z[i])
    

# xi = np.linspace(min(x), max(x), 800)
# yi = np.linspace(min(y), max(y), 800)

# X, Y = np.meshgrid(xi, yi)
# Z = griddata(x, y, z, xi, yi, interp='linear')

# ax.set_xlabel('$alpha$', fontsize = 20)
# ax.set_ylabel('$beta$', fontsize = 20)
# ax.set_zlabel('$lenght$', fontsize = 20)
# ax.set_title('', fontsize = 18)

# surf = ax.plot_surface(X, Y, Z, rstride=25, cstride=25,vmin=min(z), vmax=7660, cmap = cm.Spectral, linewidth=1, antialiased=True)

# startz, endz = ax.get_zlim()
# startx, endx = ax.get_xlim()
# ax.set_zlim3d(startz, endz)
# ax.set_xlim3d(startx, endx)
# ax.set_ylim3d(0.2, 8)

# #ax.xaxis.set_ticks(np.arange(0.4, 5, 0.2))


# fig.colorbar(surf)

# plt.show()

