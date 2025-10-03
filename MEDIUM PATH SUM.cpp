//medium path sum
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the minimum path sum from top-left to bottom-right in a grid.
     * @param grid The m x n grid of non-negative integers.
     * @return The minimum path sum.
     */
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0; // Handle empty grid case
        }

        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns

        // Step 1: Initialize the first row and first column
        // The path to any cell in the first row can only come from the left.
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        // The path to any cell in the first column can only come from above.
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        // Step 2: Fill the rest of the DP table (the grid itself)
        // For every other cell (i, j), the minimum path sum is the value of the
        // current cell plus the minimum of the cell above and the cell to the left.
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        // The minimum path sum to the bottom-right corner is stored in the last cell.
        return grid[m - 1][n - 1];
    }
};

// Main function for testing
int main() {
    Solution s;
    vector<vector<int>> grid1 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    
    // The grid will be modified in place.
    int result1 = s.minPathSum(grid1);
    cout << "Minimum Path Sum for grid1: " << result1 << " (Expected: 7)" << endl; 

    vector<vector<int>> grid2 = {
        {1, 2},
        {1, 1}
    };
    int result2 = s.minPathSum(grid2);
    cout << "Minimum Path Sum for grid2: " << result2 << " (Expected: 3)" << endl; 

    return 0;
}
