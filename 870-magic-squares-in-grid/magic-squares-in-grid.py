import numpy as np
from typing import List
class Solution:
    def is_magic_square(self, subgrid: np.ndarray) -> bool:
        # Check if all numbers from 1 to 9 are present
        if set(subgrid.flatten()) != set(range(1, 10)):
            return False
        # Calculate the sum of the diagonals
        d1 = np.sum(np.diag(subgrid))
        d2 = np.sum(np.diag(np.fliplr(subgrid)))
        # If diagonals are not equal, return False
        if d1 != d2:
            return False
        # Check if all rows and columns have the same sum as the diagonals
        if not all(np.sum(subgrid, axis=0) == d1) or not all(np.sum(subgrid, axis=1) == d1):
            return False
        return True
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        grid = np.array(grid)
        rows, cols = grid.shape
        count = 0
        for i in range(rows - 2):
            for j in range(cols - 2):
                subgrid = grid[i:i+3, j:j+3]
                if self.is_magic_square(subgrid):
                    count += 1
        return count
