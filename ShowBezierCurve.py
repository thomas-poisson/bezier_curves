import os, sys
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
#os.system('clear')

file_spec = (len(sys.argv)==2)
if not file_spec :
    print('erreur ShowBezeierCurve.py : fichier des points de controle non précisé')
    quit()

#lecture des points de controle
CPfile='./controlpoints/'+sys.argv[1]
P=np.genfromtxt(CPfile, skip_header=1, skip_footer=1)

#execution du code de calcul des points
wd=os.path.abspath(os.getcwd())
os.system(wd+'/BezCurv.exe '+sys.argv[1])

#lecture du fichier écrit par le code de calcul
T = np.loadtxt('./curves/out_'+sys.argv[1])
d=np.int(T[0,0])
nb=np.int(T[0,1])

#affichage selon la dimension
if d==2 :
    fig = plt.figure()
    ax = fig.add_subplot()
    X = T[1:nb+1,1]
    Y = T[1:nb+1,2]
    print(X)
    ax.plot(X,Y, label='Courbe Bezier par DC', linestyle='solid')
    ax.scatter(P[:,0], P[:,1], label='Points de controle', c='g', marker = 'o')
    fig.legend()
elif d==3 :
    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')

    X = T[1:nb+1,1]
    Y = T[1:nb+1,2]
    Z = T[1:nb+1,3]
    ax.plot3D(X, Y, Z, label='Courbe Bezier par DC', linestyle='solid')

    ax.scatter(P[:,0], P[:,1], P[:,2], label='Points de controle', c='g', marker = 'o')
    fig.legend()

else :
    print('erreur ShowBezeierCurve.py : probleme de dimension')
    quit()
plt.show()