class Solution {
public:
    int getVal(vector<vector<int>> &mat, vector<vector<int>> &dp , int i=0, int j=0)
    {
        int n = mat.size();
        int m = mat[0].size();    
        
        if(i == n || j == m)    return INT_MAX; 
        
        if(i == n-1 and j == m-1)
            return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;
        
        if( dp[i][j] != INT_MAX)
            return dp[i][j];
        
        int IfWeGoRight = getVal(mat , dp , i , j+1);
        int IfWeGoDown = getVal(mat , dp , i+1 , j);
        
        int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) -mat[i][j];
        
        dp[i][j] = ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;      
        return dp[i][j];
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        vector<vector<int>> dp(n , vector<int>(m , INT_MAX));
        
        return getVal(dungeon, dp);     
    }
};