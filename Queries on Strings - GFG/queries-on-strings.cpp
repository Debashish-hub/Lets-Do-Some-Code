// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    // Code here
	     unordered_map<char,int> map;
    
        vector<int> ans(Query.size());
        for(int i=0;i<Query.size();i++){
            int a=Query[i][0];
            int b=Query[i][1];
            
            for(int j=a-1;j<b;j++){
                map[str[j]]++;
            }
            ans[i]=map.size();
            map.clear();
        }
        
        return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends