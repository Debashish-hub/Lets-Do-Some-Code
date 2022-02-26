// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{
    public:
    int dp[101][101];
   
    int lcs(string a,string b,int i,int j){
        if(i == 0 || j == 0) return (0);
       
        if(dp[i][j] != -1) return (dp[i][j]);
       
        if(a[i-1] == b[j-1]){
            return dp[i][j] = 1 + lcs(a,b,i-1,j-1);
        }
       
        return dp[i][j] = max(lcs(a,b,i-1,j),lcs(a,b,i,j-1));
       
    }
   
    int build_bridges(string str1, string str2){
        memset(dp,-1,sizeof(dp));
        return lcs(str1,str2,str1.length(),str2.length());
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends