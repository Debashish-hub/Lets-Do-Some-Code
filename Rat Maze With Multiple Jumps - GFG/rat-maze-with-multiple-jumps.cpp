// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
      if(helper(matrix,ans,0,0)==false)
        return {{-1}};
       return ans;
    }
    bool isvalid(int x,int y,vector<vector<int>>matrix){
        if(x>=matrix.size() ||y>=matrix[0].size()||matrix[x][y]==0)
        return false;
        return true;
    }
    bool helper(vector<vector<int>>&matrix,vector<vector<int>>& ans,int i,int j){
        if(i==matrix.size()-1 && j==matrix[0].size()-1){
            ans[i][j]=1;
            return true;
        }
        if(isvalid(i,j,matrix)){
            ans[i][j]=1;
            for(int k=1;k<=matrix[i][j];k++){
                if(helper(matrix,ans,i,j+k)) return true;//right
                if(helper(matrix,ans,i+k,j)) return true;//down
            }
            ans[i][j]=0;
        }
        return false;
    }

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends