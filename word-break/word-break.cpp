class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        vector<bool> dp(s.size(), false);
        dp[0] = true;
        for(int i=0; i<=s.size(); i++){
            for(auto x: dict){
                if(dp[i]){
                    if(s.substr(i,x.size()) == x){
                        dp[i + x.size()] = true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};