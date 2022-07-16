class Solution {
public:
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        vector<vector<long long>> mydp(m,vector<long long>(n,0));
        vector<vector<long long>> temp(m,vector<long long>(n,0));
        int mod = (int)(1e9+7);

        for (int k=1;k<=maxMove;k++)
        {
            for (int i=0;i<m;i++)
            {
                for (int j=0;j<n;j++)
                {
                    temp[i][j]=(i==0)+(j==0)+(i==m-1)+(j==n-1); 
					if (i>0)
                        temp[i][j]+=mydp[i-1][j];
                    if (i<m-1)
                        temp[i][j]+=mydp[i+1][j];
                    if (j>0)
                        temp[i][j]+=mydp[i][j-1];
                    if (j<n-1)
                        temp[i][j]+=mydp[i][j+1];
                    
                    temp[i][j]=temp[i][j]%mod;
                }
            }
            mydp=temp; 
        }
        return mydp[sr][sc];
    }
};