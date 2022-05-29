class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, bitset<26>> mp;
        
        for (int i = 0; i < words.size(); ++i) {            
            for (auto c : words[i]) {
                mp[i][c - 'a'] = 1;
            }
        }     
        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                bool share = false;
                for (int k = 0; k < 26; ++k) {
                    if (mp[i][k] & mp[j][k]) {
                        share = true;
                        break;
                    }
                }
                
                if (!share) {
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        
        return ans;
    }
};