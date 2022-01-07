class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(string s : str){
            string x = s;
            sort(x.begin(), x.end());
            mp[x].push_back(s);
        }
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};