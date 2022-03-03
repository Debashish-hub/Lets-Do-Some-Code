// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        int n = matrix.size();
       int m = matrix[0].size();
       
       vector<pair<int, int>> direction(4);
       direction[0] = {-1, 0}; // Up
       direction[1] = {0, 1};  // Right
       direction[2] = {1, 0};  // Down
       direction[3] = {0, -1}; // Left
       
       
       int direction_index = 1;
       
       int row = 0, column = 0;
       
       while(row >=0 && row < n && column >=0 && column < m) {
           if(matrix[row][column]) {
               matrix[row][column] = 0;
               direction_index = (direction_index + 1) % 4;
           }
           
           row += direction[direction_index].first;
           column += direction[direction_index].second;
           
       }
       
       return {row - direction[direction_index].first, column - direction[direction_index].second};
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends