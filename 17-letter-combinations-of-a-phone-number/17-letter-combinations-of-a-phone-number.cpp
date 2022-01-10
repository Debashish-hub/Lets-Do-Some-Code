class Solution {
public:
    vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(string digits, string &comb, vector<string> &ans, int t){
        if(t == digits.size()){
            ans.push_back(comb);
            return;
        }
        for(auto c : map[digits[t] - '2']){
            comb.push_back(c);
            solve(digits, comb, ans, t+1);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0){
            return ans;
        }
        string comb = "";
        solve(digits, comb, ans, 0);
        return ans;
    }
};