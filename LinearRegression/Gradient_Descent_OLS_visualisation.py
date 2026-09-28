import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

auto_df = pd.read_csv(
        "auto-mpg.data",
        sep=r'\s+(?=(?:[^"]*"[^"]*")*[^"]*$)',
        header=None,
        engine='python',
        names = [
            "mpg", "cylinders", "displacement", "horsepower",
            "weight", "acceleration", "year", "origin", "name"
        ]
    )

gd_df = pd.read_csv(
        "gradient_descent_function.csv",
        header=None
        )

ols_y_intercept = 46.3174 
ols_slope = -0.00767661

gd_y_intercept = gd_df.iloc[0,0]
gd_slope = gd_df.iloc[0,1]

x = np.linspace(-5000, 5000, 1000)

ols_function = ols_y_intercept + ols_slope * x 
gd_function = gd_y_intercept + gd_slope * x

plt.scatter(auto_df["weight"],auto_df["mpg"], s = 20, marker=".")
plt.plot(x, ols_function, label="ols")
plt.plot(x, gd_function, label="gd")


plt.gca().spines["left"].set_position("zero")
plt.gca().spines["bottom"].set_position("zero")
plt.gca().spines["top"].set_visible(False)
plt.gca().spines["right"].set_visible(False)

plt.legend()
plt.show()

