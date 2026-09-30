import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

banknote_df = pd.read_csv("banknote_authentication.csv")
weights_df = pd.read_csv("weights.csv")

x = np.linspace(-10,10,100)
sigmoid_function = 1/(1 + 1/np.exp(x))



plt.plot(x,sigmoid_function, label="sigmoid")

plt.legend()
plt.show()




