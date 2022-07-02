// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	void topoSort(vector<int> adj[], int u, vector<int> &vis, stack<int> &st) {
        vis[u] = 1;
        for (int v: adj[u]) {
            if (!vis[v]) topoSort(adj, v, vis, st);
        }
        st.push(u);
    }
    int solve(vector<int> adj[], int n, int s, int d) {
       vector<int> vis(n, 0);
    	stack<int> st;
    	for (int i = 0; i < n; i++) {
    		if (!vis[i]) topoSort(adj, i, vis, st);
    	}
    	vector<int> path(n, 0);
    	path[s] = 1;
    	while (!st.empty()) {
    		int u = st.top();
    		st.pop();
    	    for (int v: adj[u]) path[v] += path[u];    
    	}
    	return path[d];
    }
    int possible_paths(vector<vector<int>>edges, int n, int s, int d){
    	    // Code here
    	vector<int> adj[n];
    	for (int i = 0; i < edges.size(); i++) {
    		int u = edges[i][0], v = edges[i][1];
    	    adj[u].push_back(v);
    	}
    	return solve(adj, n, s, d);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends