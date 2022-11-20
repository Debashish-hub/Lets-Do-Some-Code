class Solution {
public:
    int calculate(string s) {
        long long int sign = 1, currNo = 0, ans = 0;
        
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if (isdigit(s[i])) {
                currNo = (s[i] - '0');
                while(i + 1 < s.size() and isdigit(s[i+1])) currNo = currNo * 10 + (s[i+1] - '0'),i++;
                ans = ans + sign * currNo;
                currNo = 0;
                sign = 1;
            } else if (s[i] == '+') {
                sign = 1; 
            }else if (s[i] == '-') sign = -1;
            else if (s[i] == '(') {
                st.push(ans);
                st.push(sign);
                sign = 1;
                ans = 0;
            } else if (s[i] == ')') {
                int tempSign = st.top();
                st.pop();
                ans = ans * tempSign;
                int currAns = st.top();
                st.pop();
                ans = ans + currAns;
            } else {}
        }

        return ans;
    }
};