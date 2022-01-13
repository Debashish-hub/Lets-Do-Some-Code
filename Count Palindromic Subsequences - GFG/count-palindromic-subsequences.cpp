// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long dp[1001][1001];
    int mod = 1e9+7;
    long long solve( int i, int j, string& str){
        if(i > j){
            return 0;
        }
        if(i == j){
            return 1;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(str[i] == str[j]){
            return dp[i][j] = (1 + solve( i+1, j, str) + solve( i, j-1, str)) % mod;
        }else{
            return dp[i][j] = (mod + solve( i+1, j, str) + solve( i, j-1, str) - 
            solve(i+1, j-1, str)) % mod;
        }
    }
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code 
       int n = str.length();
       memset(dp, -1, sizeof(dp));
       return solve( 0, n-1, str);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends