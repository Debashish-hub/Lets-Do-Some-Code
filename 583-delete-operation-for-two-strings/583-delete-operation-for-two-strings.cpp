class Solution {
public:
    int minDistance(string word1, string word2) {
        int row  = word1.size(), col = word2.size();
        int dp[row+1][col+1];
        for(int i=0;i<=row;++i) dp[i][0]=0;
        for(int j=0;j<=col;++j) dp[0][j]=0;
        
        for(int i=1;i<=row;++i)
        {
            for(int j=1;j<=col;++j)
            {
                if(word1[i-1] == word2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return (row+col)-(2*dp[row][col]);
    }
};