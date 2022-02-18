class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(auto &ch : num){
            while(s.size() && s.top() > ch && k) s.pop(), k--;      //until the top() of the stack is greater than the curr digit, keep popping because we don't want those digits in the final stack & remember to decrement k after each pop
            if(s.empty() && ch == '0') continue;     //we don't want leading 0's in the result
            else s.push(ch);   
        }
        while(!s.empty() && k) s.pop(), k--;   //for numbers having digits in ascending order & k < such digits length
        
        string ans = "";
        while(s.size()){
            ans = s.top() + ans;   //Do this so we don't have to reverse the string again
            s.pop();
        }
        return ans.size() > 0 ? ans : "0";   //If there remain any digits in teh stack, only then we can return a nu,ber, else we return 0.
    }
    
};