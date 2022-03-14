// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int biGraph(int arr[], int n, int e) {
        // code here
       
        
        vector<int> adj[n];
        for(int i=0; i<2*e; i+=2){
            adj[arr[i]].push_back(arr[i+1]);
            adj[arr[i+1]].push_back(arr[i]);
        }
        vector<int> vis(n,0);
        vector<int> tin(n,-1);//time of insertion
        vector<int> low(n,-1);//lowest possible time to reach
        int timer = 0;
        vector<int> isArticulation(n,0);
        bool ok = false;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(ok){
                    //CC > 1
                    return 0;
                }
                dfs(i,-1,vis,tin,low,timer,adj,isArticulation);
                ok = true;
            }
        }
        for(int i=0; i<n; i++){
            if(isArticulation[i] == 1){
                return 0;
            }
        }
        return 1;
    }
    void dfs(int node,int parent,vector<int> &vis,vector<int> &tin,vector<int> &low,int &timer,vector<int> adj[],vector<int> &isArticulation){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;
        for(auto it:adj[node]){
            if(it == parent){
                continue;
            }
            if(!vis[it]){
                dfs(it,node,vis,tin,low,timer,adj,isArticulation);
                low[node] = min(low[node],low[it]);
                if(low[it] >= tin[node] && parent!=-1){
                    //compulsorily must visit from parent i.e node
                    isArticulation[node] = 1;
                    
                }
                child += 1;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
            
        }
        if(parent == -1 && child>1){
            isArticulation[node] = 1;
        }
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}  // } Driver Code Ends