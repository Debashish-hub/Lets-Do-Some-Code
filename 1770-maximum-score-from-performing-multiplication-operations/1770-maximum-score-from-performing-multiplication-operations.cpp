class Solution {
private:
    int f(int i, int j,int ind ,vector<int>& nums, vector<int>& multipliers,  vector<vector<int>> &dp){
        
        if(ind==multipliers.size()) return 0;
        
        if(dp[ind][i] != INT_MIN) return dp[ind][i];
        
        // pick from begin
        int pickBigin = nums[i] * multipliers[ind] + f(i+1, j,ind+1,  nums, multipliers, dp);
        
        // pick from end
        
        int pickEnd = nums[j] * multipliers[ind] +  f(i, j-1,ind+1, nums, multipliers, dp);
        
        
        return dp[ind][i] = max(pickBigin, pickEnd);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m,vector<int>(m,INT_MIN));
        return f(0, n-1,0, nums, multipliers, dp);
    }
};