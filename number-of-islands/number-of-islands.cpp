class Solution {
public:
    bool dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (grid[i][j] == '0') return false;
        grid[i][j] = '0';
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int counter = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(grid, i, j)) counter++;
        return counter;
    }
};