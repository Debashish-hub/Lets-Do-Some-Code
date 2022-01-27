class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1;
        int n = s.length();
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == '+' || s[i] == '-') {
                res += sign * num;
                sign = s[i] == '+' ? 1 : -1;
                num = 0;
            } else if (s[i] == ' ') {
                continue;
            } else if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else {
                int cnt = 0;
                int j = i;
                for (; i < n; i++) {
                    if (s[i] == '(') cnt++;
                    if (s[i] == ')') cnt--;
                    if (cnt == 0) break;
                }
                num = calculate(s.substr(j + 1, i - j - 1));
            }
        }
        return res;
    }
};