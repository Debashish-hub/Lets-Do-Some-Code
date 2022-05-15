// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void func(vector<int>&arr,set<vector<int>>&sol,vector<int>&dp,int n,int ind){
       if(ind==n){
           vector<int>lol=dp;
           sort(lol.begin(),lol.end());
           sol.insert(lol);
           return ;
       }
       func(arr,sol,dp,n,ind+1);
       dp.push_back(arr[ind]);
       func(arr,sol,dp,n,ind+1);
       dp.pop_back();
       
   }
   //Function to find all possible unique subsets.
   vector<vector<int> > AllSubsets(vector<int> arr, int n)
   {
       // code here 
       set<vector<int>>sol;
       vector<vector<int>>ans;
       vector<int>dp;
       func(arr,sol,dp,n,0);
       for(auto it:sol){
           ans.push_back(it);
       }
       sort(ans.begin(),ans.end());
       return ans;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends