class Solution {
public:
    int cnt = 0;
    
    bool isSafe(vector<vector<int>>& board, int i, int j, int n) {
        int x = i;
        int y = j;
        
        while(x--)
            if(board[x][y])
                return false;
        
        x = i;
        y = j;
        
        while(x>=0 and y >= 0)
            if(board[x--][y--])
                return false;
        
        x = i;
        y = j;
        
        while(x >= 0 and y < n)
            if(board[x--][y++])
                return false;
        
        return true;
    }
    
    bool solve(vector<vector<int>>& board, int i, int n) {
        if(i == n) {
            cnt++;
            
            //to check for other solutions return false;
            return false;
        }
        
        for(int j = 0; j < n; j++) {
            if(isSafe(board, i, j, n)) {
                board[i][j] = 1;
                
                bool kyaQueenRakhPaaRaheHai = solve(board, i+1, n);
                
                if(kyaQueenRakhPaaRaheHai)
                    return true;
                
                board[i][j] = 0;
            }
        }
        
        return false;
    }
    
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(board, 0, n);
        return cnt;
    }
};