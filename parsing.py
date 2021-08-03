import pandas as pd

print("Limpiando la data")
df = pd.read_csv("green_tripdata_2015-01.csv", sep=',', index_col=False)

start_x = "Pickup_longitude"
start_y = "Pickup_latitude"
end_x = "Dropoff_longitude"
end_y = "Dropoff_latitude"

indexes_to_delete = df[(df[start_x] == 0) | (df[start_y] == 0) | (df[end_x] == 0) | (df[end_y] == 0)].index
final_df = df.drop(indexes_to_delete)
final_df.index = pd.RangeIndex(len(final_df.index))

final_df.to_csv("green_tripdata_2015-01.csv", index=False)
print("Data limpia")