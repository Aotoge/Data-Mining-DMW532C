import numpy as np
import pandas as pd
from copy import deepcopy
from matplotlib import pyplot as plt

def euclidean(a, b, ax):
    dis = np.linalg.norm(a - b, axis=ax)
    return dis


X = pd.read_csv("Absenteeism_at_work.csv")
category = 'Age'
x1 = X[category].values
x2 = X['Absenteeism time in hours'].values
plt.scatter(x1, x2, s=7)
plt.show()

k = 3
C1 = np.random.uniform(np.min(x1), np.max(x1), size=k)
C2 = np.random.uniform(np.min(x2), np.max(x2), size=k)
C = np.array(list(zip(C1, C2)), dtype=np.float32)

print("Randomly chosen centroids\n"+str(C))
plt.scatter(x1, x2, s=7)
plt.scatter(C1, C2, marker='P', c='k')
plt.show()

C_prev = np.zeros(C.shape)
labels = np.zeros(len(X))
E = euclidean(C, C_prev, None)

while E != 0:
    for i in range(len(X)):
        distances = euclidean((x1[i],x2[i]), C, 1)
        cluster = np.argmin(distances)
        labels[i] = cluster
    C_prev = deepcopy(C)
    for i in range(k):
        points = []
        for j in range(len(X)):
            if labels[j] == i:
                points.append((x1[j],x2[j]))
        points = np.array(points)
        C[i] = np.mean(points, axis=0)
    E = euclidean(C, C_prev, None)


colors = ['y', 'c', 'm', 'r', 'g', 'b']
for i in range(k):
    points = []
    for j in range(len(X)):
        if labels[j] == i:
            points.append((x1[j],x2[j]))
    points = np.array(points)
    plt.scatter(points[:, 0], points[:, 1], s=7, c=colors[i])
plt.scatter(C[:, 0], C[:, 1], marker='P', c='k')
plt.show()

print("Final centroids\n"+str(C))
