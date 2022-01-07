class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;

        int i = 0, j = 0, ans = 0, n = s.size();

        while(i <n && j<n){
            if(set.find(s[i]) == set.end()){
                set.insert(s[i++]);
                ans = max(ans, i-j);
            }else{
                set.erase(s[j++]);
            }
        }
        return ans;
    }
};