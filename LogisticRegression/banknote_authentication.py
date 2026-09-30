import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

banknote_df = pd.read_csv("banknote_authentication.csv")
points_df = pd.read_csv("points.csv", header=None)

x = np.linspace(-10,10,100)
sigmoid_function = 1/(1 + 1/np.exp(x))


plt.scatter(-np.log((1 - points_df[0])/points_df[0]),points_df[0], s = 20, marker=".", color="red", label="predictions")
plt.plot(x,sigmoid_function, label="sigmoid")

plt.legend()
plt.show()




