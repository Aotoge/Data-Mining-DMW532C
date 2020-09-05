import random
import numpy as np
import pandas as pd
from copy import deepcopy
from matplotlib import pyplot as plt
from scipy.spatial.distance import cdist

X = pd.read_csv("Absenteeism_at_work.csv")

def distance(a, b, ax):
    dis = np.linalg.norm(a - b, axis=ax)
    # print(dis)
    return dis

category = 'Age'
x1 = X[category].values
x2 = X['Absenteeism time in hours'].values
plt.scatter(x1, x2, s=7)
plt.show()

k = 4

rand_idx = random.sample(list(range(0,len(x1))),k)
C1, C2 = [], []
for i in range(k):
    C1.append(x1[rand_idx[i]])
    C2.append(x2[rand_idx[i]])

C = np.array(list(zip(C1, C2)), dtype=np.float32)

print("Randomly chosen Medoids\n"+str(C))
plt.scatter(x1, x2, s=7)
plt.scatter(C1, C2, marker='P', c='k')
plt.show()

labels = np.zeros(len(X))
labels_new = np.zeros(len(X))
C_prev = np.zeros(C.shape)
E = distance(C, C_prev, None)

while E != 0:
    C_prev = deepcopy(C)
    #for each medoid
    for i in range(k):
        #cost calc prev
        cost_prev = 0
        for j in range(len(X)):
            dist = distance((x1[j],x2[j]), C, 1)
            cost_prev += min(dist)
            labels[j] = np.argmin(dist)
        
        #for each non-medoid
        for j in range(len(X)):
            new_med = np.array([x1[j],x2[j]])
            if(new_med not in C):                
                med_old = C[i]
                C[i] = new_med
                cost_new = 0
                for it in range(len(X)):
                    dist = distance((x1[it],x2[it]), C, 1)
                    cost_new += min(dist)                    
                    labels_new[it] = np.argmin(dist)
                    # print(str(dist)+" : "+str(min(dist))+" : "+str(labels_new[it]))
                if(cost_new<cost_prev):
                    cost_prev = cost_new
                    labels = deepcopy(labels_new)
                    # print(str(cost_new)+"<"+str(cost_prev))
                else:
                    C[i] = med_old
    E = distance(C, C_prev, None)           

colors = ['y', 'c', 'm', 'r', 'g', 'b']
for i in range(k):
    points = []
    for j in range(len(X)):
        if labels[j] == i:
            points.append((x1[j],x2[j]))
    points = np.array(points)
    plt.scatter(points[:, 0], points[:, 1], s=7, c=colors[i])

plt.show()

print("Final Medoids\n"+str(C))