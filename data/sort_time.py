# import pandas
import pandas as pd

# create dataframe from data and label columns
df = pd.read_csv('soc-sign-bitcoinalpha.csv', names=["SOURCE", "TARGET", "RATING", "TIME"])

# sort dataframe by time
df = df.sort_values(by=["TIME"])

# write dataframe to new sorted csv
df.to_csv('sorted_soc-sign-bitcoinalpha.csv', index=False)