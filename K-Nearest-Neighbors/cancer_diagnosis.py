import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

cancerTraining_df = pd.read_csv("KNNAlgorithmDataset_training.csv", header=None)

cancerTest_df = pd.read_csv("KNNAlgorithmDataset_test.csv", header=None)

training_M = cancerTraining_df[cancerTraining_df[1] == "M"]
training_B = cancerTraining_df[cancerTraining_df[1] == "B"]

test_M = cancerTest_df[cancerTest_df[1] == "M"]
test_B = cancerTest_df[cancerTest_df[1] == "B"]

plt.scatter(training_M[2], training_M[3], s = 20, marker=".", color="blue", label="positiv")
plt.scatter(training_B[2], training_B[3], s = 20, marker=".", color="negativ")

plt.scatter(test_M[2], test_M[3], s = 20, marker="x", color="blue")
plt.scatter(test_B[2], test_B[3], s = 20, marker="x", color="green")

plt.show()

