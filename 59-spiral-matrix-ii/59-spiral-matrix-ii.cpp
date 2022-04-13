class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n));
        int rstart = 0, rend = n-1, cstart = 0, cend = n-1;
        int count = 1;
        while(rstart <= rend && cstart <= cend){
            for(int i=cstart; i<=cend; i++){
                res[rstart][i] = count;
                count++;
            }
            rstart++;
            for(int i=rstart; i<=rend; i++){
                res[i][cend] = count;
                count++;
            }
            cend--;
            for(int i=cend; i>=cstart; i--){
                res[rend][i] = count;
                count++;
            }
            rend--;
            for(int i=rend; i>=rstart; i--){
                res[i][cstart] = count;
                count++;
            }
            cstart++;
        }
        return res;
    }
};