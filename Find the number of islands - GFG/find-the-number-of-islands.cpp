// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void numislands(vector<vector<char>> &grid,int islands,int i,int j, int n,int m)
    {  
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == '0')
          return;
        grid[i][j] = '0';
        int x[8] = { 0,0,1,-1,-1,-1,1, 1 };
        int y[8] = {-1,1,0, 0, 1,-1,1,-1 };
        for(int k=0; k < 8; k++)
          numislands(grid,islands,i + x[k] , j + y[k] ,n,m);

    } 
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(),m = grid[0].size();
        int islands = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
           {
               if(grid[i][j] == '1')
                  numislands(grid,islands,i,j,n,m),islands++;
   
        }
        }
        return islands;
    
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends