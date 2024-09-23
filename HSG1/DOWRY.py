https://www.programiz.com/python-programming/online-compiler/

import numpy as np

# Step 1: Generate a 100x100 matrix with random integer values
matrix = np.random.randint(low=-10, high=11, size=(10, 10))

# Step 2: Adjust the values in the first two rows to ensure their sum equals 2/3 of the total sum
total_sum = np.sum(matrix)
target_sum_first_two_rows = 2/3 * total_sum
current_sum_first_two_rows = np.sum(matrix[:2])
difference = target_sum_first_two_rows - current_sum_first_two_rows
matrix[:2] = (matrix[:2] + difference // 100).astype(int)  # Convert to integers

# Step 3: Adjust the remaining values to ensure the sum of all elements mod 3 equals 0
matrix_flat = matrix.flatten()
remaining_sum = total_sum - np.sum(matrix[:2])
remainder = remaining_sum % 3
if remainder == 1:
    # Add 1 to a random element
    index = np.random.randint(0, 10)
    matrix_flat[index] += 1
elif remainder == 2:
    # Subtract 1 from a random element
    index = np.random.randint(0, 10)
    matrix_flat[index] -= 1

# Reshape the flattened matrix to its original shape
matrix = matrix_flat.reshape((10, 10))

for row in matrix:
    print(" ".join(map(str, row)))
print("Total sum:", np.sum(matrix))
print("Sum of all elements mod 3:", np.sum(matrix) % 3)

