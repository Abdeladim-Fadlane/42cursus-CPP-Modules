import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def update(frame):
    global grid
    new_grid = grid.copy()
    for i in range(rows):
        for j in range(cols):
            # Count the number of alive neighbors
            neighbors = np.sum(grid[max(0, i-1):min(rows, i+2), max(0, j-1):min(cols, j+2)]) - grid[i, j]
            # Apply the rules of the Game of Life
            if grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                new_grid[i, j] = 0
            elif grid[i, j] == 0 and neighbors == 3:
                new_grid[i, j] = 1
    grid = new_grid
    img.set_array(grid)
    return [img]

# Set the size of the grid
rows, cols = 50, 50
# Create a random initial grid
grid = np.random.choice([0, 1], size=(rows, cols))
# Set up the plot
fig, ax = plt.subplots()
ax.set_facecolor('black')  # Set the background color to black
img = ax.imshow(grid, interpolation='nearest', cmap='gray')  # Use the 'gray' colormap for a dark appearance
ani = animation.FuncAnimation(fig, update, frames=100, interval=200, blit=True)
plt.show()
