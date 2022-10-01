class Solution {
public:
    int numDecodings(string s) {
        int ways[101] = {0};
        ways[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i - 1] > '0') {
                ways[i] += ways[i - 1];
            }
            
            if (i < 2) {
                continue;
            }
            
            int num = stoi(s.substr(i - 2, 2));
            if (10 <= num && num <= 26) {
                ways[i] += ways[i - 2];
            }
        }
        
        return ways[s.size()];
    }
};