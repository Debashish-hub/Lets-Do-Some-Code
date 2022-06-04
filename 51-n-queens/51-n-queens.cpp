class Solution {
public:
    void recurse(vector<vector<string>>& res, vector<string>& temp, int row, int& n){
        if(row==n){
            res.push_back(temp);
            return;
        }
        bool flag;
        for(int i=0; i<n; i++){     // To check for queens in the same column 
            flag=true;
            for(int j=0; j<row; j++){
                if(temp[j][i]=='Q'){
                    flag=false;
                    break;
                }
            }
            if(!flag){
                continue;
            }
            for(int j=1; j<=row && i-j>=0; j++){    // To check for queens on the left upper diagonal
                if(temp[row-j][i-j]=='Q'){
                    flag=false;
                    break;
                }
            }
            if(!flag){
                continue;
            }
            for(int j=1; j<=row && i+j<n; j++){     // To check for queens on the right upper diagonal
                if(temp[row-j][i+j]=='Q'){
                    flag=false;
                    break;
                }
            }
            if(flag){   // It is possible to put a queen at [row][j]
                string s="";
                for(int j=0; j<i; j++){
                    s+=".";
                }
                s+="Q";
                for(int j=i+1; j<n; j++){
                    s+=".";
                }
                temp.push_back(s);
                recurse(res, temp, row+1, n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp = {};
        recurse(res, temp, 0, n);
        return res;
    }
};
