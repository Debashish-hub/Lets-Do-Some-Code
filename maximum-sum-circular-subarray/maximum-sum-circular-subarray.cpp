class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSum = 0, size = A.size(), curSum = 0, maxE = -30001;
        vector<int> dp(size, -30001);
        for(int i = 0, sum = 0; i < size; ++i) {
            dp[i] = i == 0 ? sum += A[i] : max(dp[i-1], sum += A[i]);
            maxE = max(maxE, A[i]);
            curSum = max(curSum+A[i], 0);
            maxSum = max(maxSum, curSum);
        }
        if(maxE < 0) return maxE;
        
        for(int i = size-1, sum = 0; i >= 1; --i)
            maxSum = max(maxSum, dp[i-1] + (sum += A[i]));
			
        return maxSum;
    }
};