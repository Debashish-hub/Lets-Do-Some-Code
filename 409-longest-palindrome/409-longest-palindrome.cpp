class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128] = {};
        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
        }
        int odd = 0;
        for(auto i : freq){
            odd += i & 1;
        }
        return s.size() - odd + (odd > 0);                
    }
};