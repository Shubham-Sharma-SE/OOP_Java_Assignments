import pandas as pd
import numpy as np
import math

df = pd.read_excel("Tutorial_Datasets_Probability_Statistics.xlsx", sheet_name="T1_Student_Marks")
data = df["Marks"].dropna().tolist()

total = sum(data)
mean = total / len(data)

data.sort()
n = len(data)
if n % 2 == 0:
    median = (data[n//2 - 1] + data[n//2]) / 2
else:
    median = data[n//2]

freq = {}
for x in data:
    freq[x] = freq.get(x, 0) + 1

max_freq = max(freq.values())
mode = [k for k, v in freq.items() if v == max_freq]

variance = sum((x - mean) ** 2 for x in data) / len(data)
std_dev = math.sqrt(variance)

numpy_mean = np.mean(data)
numpy_median = np.median(data)
numpy_mode = pd.Series(data).mode().tolist()
numpy_variance = np.var(data)
numpy_std = np.std(data)

print("========== MANUAL ==========")
print("Mean:", mean)
print("Median:", median)
print("Mode:", mode)
print("Variance:", variance)
print("Std Dev:", std_dev)

print("\n========== NUMPY/PANDAS ==========")
print("Mean:", numpy_mean)
print("Median:", numpy_median)
print("Mode:", numpy_mode)
print("Variance:", numpy_variance)
print("Std Dev:", numpy_std)

print("\n========== COMPARISON ==========")
print(f"{'Measure':<15}{'Manual':<15}{'NumPy/Pandas'}")
print("-" * 40)
print(f"{'Mean':<15}{mean:<15.2f}{numpy_mean:.2f}")
print(f"{'Median':<15}{median:<15.2f}{numpy_median:.2f}")
print(f"{'Variance':<15}{variance:<15.2f}{numpy_variance:.2f}")
print(f"{'Std Deviation':<15}{std_dev:<15.2f}{numpy_std:.2f}")