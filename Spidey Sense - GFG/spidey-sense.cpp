// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int m, int n) 
    { 
        // Your code goes 
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='B')
                {
                    q.push({i,j});
                    vis[i][j]=0;
                }
                else if(matrix[i][j]=='W')
                vis[i][j]=-1;
                else if(matrix[i][j]=='O')
                vis[i][j]=-10;
            }
        }
        int cou=1;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        while(!q.empty())
        {
            int temp=q.size();
            while(temp--)
            {
                auto it=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int x=dx[i]+it.first;
                    int y=dy[i]+it.second;
                    if(x>=0 and y>=0 and x<m and y<n and vis[x][y]==-10)
                    {
                        q.push({x,y});
                        vis[x][y]=cou;
                    }
                }
            }
            cou++;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==-10)
                vis[i][j]=-1;
            }
        }
        return vis;
    } 
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends