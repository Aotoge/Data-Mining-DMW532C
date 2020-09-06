import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from matplotlib import pyplot as plt

data = pd.read_csv("Iris.csv")
X = data.iloc[:,1:5]
labels = data['Species']
Y = []
for l in labels:
    if l == 'Iris-setosa':
        Y.append(-1.0)
    else:
        Y.append(1.0)
Y = np.array(Y)

# print(X)
# print(Y)
# print(Y.value_counts())

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.1, stratify = Y, random_state = 1)
X_test = X_test.values
X_train = X_train.values

class Perp:

    def __init__(self):
        self.w = None
        self.b = None

    def activation_fn(self, x):
        if np.dot(self.w,x) + self.b >= 0.0:
            return 1.0
        else:
            return 0.0

    def predict(self, X):
        Y = []
        for tup in X:
            y = self.activation_fn(tup)
            Y.append(y)
        return np.array(Y)

    def fit(self, X, Y, epocs, l_rate):
        self.w = np.ones(X.shape[1])
        self.b = 0.0
        error = {}
        min_err = 100.0
        opt_w = np.ones(X.shape[1])
        opt_b = 0.0

        for i in range(epocs):
            error[i] = 0.0
            for x, y in zip(X, Y):
                y_dash = self.activation_fn(x)
                update = l_rate*(y-y_dash)
                self.w += update*x
                self.b += update
                error[i] += int(update!=0.0)
            error[i] /= len(Y)
            # print(i,error[i])
            if error[i]<=min_err:
                # print(i)
                min_err = error[i]
                opt_w = self.w
                opt_b = self.b
        
        self.w = opt_w
        self.b = opt_b

        print("Training Error:%f" %(min_err))
        plt.plot(error.values())
        plt.show()


perp = Perp()
perp.fit(X_train, Y_train, 100, 0.001)

print("Weights:"+str(perp.w)+"\nBias:"+str(perp.b))
pred_result = perp.predict(X_test)

error = 0.0
for y_, y in zip(pred_result,Y_test):
    error+=y_-y
error /= len(Y_test)
print("Testing Error: "+str(error))