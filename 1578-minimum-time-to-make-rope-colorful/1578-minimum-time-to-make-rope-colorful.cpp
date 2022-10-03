class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int dp[neededTime.size()];
        int sum=0;
        dp[0]=neededTime[0];
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]==colors[i-1])
            {
                dp[i]=max(neededTime[i],dp[i-1]);

                sum+=min(neededTime[i],dp[i-1]);
            }
            else
                dp[i]=neededTime[i];
        }
        return sum;
    }
};