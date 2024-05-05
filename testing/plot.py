import os
import matplotlib.pyplot as plt

# Function to read data from a file
def read_data(filename):
    data = []
    with open(filename, 'r') as file:
        for line in file:
            parts = line.split()
            data.append((int(parts[0]), int(parts[1]), float(parts[2]), float(parts[3]), float(parts[4])))
    return data

# Function to plot and save the plot
def plot_and_save(data, output_filename, n):
    # Extracting data for each method
    jen_schmidt = [d[2] for d in data]
    tarjan = [d[3] for d in data]
    tarjan_ext = [d[4] for d in data]

    # Plotting
    plt.plot(jen_schmidt, label='Jen-Schmidt')
    plt.plot(tarjan, label='Tarjan')
    plt.plot(tarjan_ext, label='Tarjan_extended')

    title= "Comparison of Algorithms"
    title = title + " (n = " + str(n) + ")"
    # Adding labels and title
    plt.xlabel('Number of Edges')
    plt.ylabel('Time (in ms)')
    plt.title(title)
    plt.legend()

    # Saving the plot
    plt.savefig(output_filename)
    plt.close()

# Directory containing the data files
data_dir = '.'

# Directory to save plots
plot_dir = 'plots/'

# Creating the plots directory if it doesn't exist
if not os.path.exists(plot_dir):
    os.makedirs(plot_dir)

# Iterate over files
for filename in os.listdir(data_dir):
    if filename.startswith("output_"):
        # Read data
        data = read_data(os.path.join(data_dir, filename))
        # Extract n from filename
        n = int(filename.split('_')[1][:-4])
        # Plot and save
        output_filename = os.path.join(plot_dir, f'plot_{n}.png')
        plot_and_save(data, output_filename, n)

print("Plots saved successfully.")
