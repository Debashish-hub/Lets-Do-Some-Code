class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int memo[triangle.size()];
        int n = triangle.size() - 1;

        for (int i = 0; i < triangle[n].size(); i++)
            memo[i] = triangle[n][i];   

        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j < triangle[i].size(); j++)
                memo[j] = triangle[i][j] + min(memo[j], memo[j + 1]);

        return memo[0];
    }
};