class Solution {
public:

    int getMaximumGold(vector<vector<int>>& grid) {

        int maxGold = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, DFS(grid, i, j));
                }
            }
        }

        return maxGold;
    }

    int DFS(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }

        int origGoldValue = grid[i][j];
        grid[i][j] = 0;

        int up = DFS(grid, i - 1, j);
        int down = DFS(grid, i + 1, j);
        int left = DFS(grid, i, j - 1);
        int right = DFS(grid, i, j + 1);

        grid[i][j] = origGoldValue;

        return origGoldValue + max(max(up, down), max(left, right));
    }
};