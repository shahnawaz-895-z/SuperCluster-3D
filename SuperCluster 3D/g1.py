import matplotlib.pyplot as plt
import pandas as pd
import numpy as np 
import seaborn as sns
df = pd.read_csv("q2_output.csv")
sns.scatterplot(x=df.income, y=df.score, 
                hue=df.cluster, 
                palette=sns.color_palette("hls", n_colors=4))
plt.xlabel("Annual income (k$)")
plt.ylabel("Spending Score (1-100)")
plt.title("Clustered: spending (y) vs income (x)")

plt.show()