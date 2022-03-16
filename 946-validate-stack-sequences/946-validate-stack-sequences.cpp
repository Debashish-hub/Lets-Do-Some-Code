class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pu = pushed.size(), po = popped.size();
        int i=0, j =0;
        stack<int> st;
        while(i < pu && j < po){
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty();
    }
};