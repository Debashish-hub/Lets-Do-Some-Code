// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int find_max(vector<vector<int>> & arr){
       int mx = 0;
       for(int i = 0; i < arr.size(); i++){
           mx = max(mx,arr[i][0]);
       }
       return (mx);
   }
   
   int maxBinTreeGCD(vector<vector<int>> arr, int N) {
       if(N <= 2) return (0);
       vector<int> mp[find_max(arr)+1];
       vector<int> num;
       for(int i = 0; i < arr.size(); i++){
           mp[arr[i][0]].push_back(arr[i][1]);
           num.push_back(arr[i][0]);
       }
       
       int ans = 0;
       for(int i = 0; i < num.size(); i++){
           int n = num[i];
           if(mp[n].size() == 2){
               ans = max(ans,__gcd(mp[n][0],mp[n][1]));
           }
       }
       
       return (ans);
   }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends