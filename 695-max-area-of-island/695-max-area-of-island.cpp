class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) res = max(res, dfs(grid, m, n, i, j));
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& grid, int m, int n, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || !grid[i][j]) return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid,m,n,i+1,j)+dfs(grid,m,n,i-1,j)+dfs(grid,m,n,i,j+1)+dfs(grid,m,n,i,j-1);
    }
};