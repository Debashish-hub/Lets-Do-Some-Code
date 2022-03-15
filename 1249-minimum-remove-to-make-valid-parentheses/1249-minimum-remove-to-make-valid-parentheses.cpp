class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    s[i] = '0';
                }
            }
        }
        while(!st.empty()){
            s[st.top()] = '0';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        return s;
    }
};

