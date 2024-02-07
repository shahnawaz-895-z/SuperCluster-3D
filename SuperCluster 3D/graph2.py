
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np 
import seaborn as sns

df = pd.read_csv("q2_output.csv")

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.scatter(df.age, df.income, df.score, c=df.cluster, cmap='viridis')

ax.set_xlabel("Age")
ax.set_ylabel("Annual Income (k$)")
ax.set_zlabel("Spending Score (1-100)")
ax.set_title("Clustered: age (x) vs income (y) vs Score(z)")

plt.show()