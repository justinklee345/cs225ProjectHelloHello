# import pandas
import pandas as pd

# create dataframe from data and label columns
df = pd.read_csv('soc-sign-bitcoinalpha.csv', names=["SOURCE", "TARGET", "RATING", "TIME"])

# sort dataframe by TIME
df = df.sort_values(by=["TIME"])

# write dataframe to new sorted csv
df.to_csv('sorted-soc-sign-bitcoinalpha.csv', index=False)

# subtract one from SOURCE and TARGET so node id starts at 0
df["SOURCE"] -= 1
df["TARGET"] -= 1

# write dataframe to new 0 indexed csv
df.to_csv('sorted-zero-soc-sign-bitcoinalpha.csv', index=False)