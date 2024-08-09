class Solution {
public:
    bool solve(int x, int y, vector<vector<int>>& grid) {
        vector<int> row(3), col(3);
        vector<int> vis(16, 0);  // Initialize with 0
        int d1 = 0, d2 = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[x + i][y + j];
                vis[num]++;
                row[i] += num;
                col[j] += num;
                if (i == j) d1 += num;
                if (i + j == 2) d2 += num;
            }
        }
        // Early return if diagonals don't match
        if (d1 != d2) return false;
        // Check if all rows and columns have the same sum as the diagonals
        for (int i = 0; i < 3; i++) {
            if (row[i] != d1 || col[i] != d1) return false;
        }
        // Check if numbers 1 through 9 are all present exactly once
        for (int i = 1; i <= 9; i++) {
            if (vis[i] != 1) return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;

        // Ensure grid is large enough for a 3x3 subgrid
        if (grid.size() < 3 || grid[0].size() < 3) return 0;

        // Iterate over each possible starting position for a 3x3 subgrid
        for (int i = 0; i <= grid.size() - 3; i++) {
            for (int j = 0; j <= grid[0].size() - 3; j++) {
                // Check if the subgrid starting at (i, j) is a magic square
                if (solve(i, j, grid)) cnt++;
            }
        }
        return cnt;
    }
};
