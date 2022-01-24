class Solution {
public:
    bool detectCapitalUse(string s) {
        bool first=false;
        int cap=0,sm=0;
        if(s[0]>=65 && s[0]<=90) first=true;
        for(int i=1;i<s.length();i++){
            if(s[i]>=65 && s[i]<=90) cap++;
            else if(s[i]>=97 && s[i]<=122) sm++;
        }
        if(first && cap==s.length()-1) return true;
        else if(sm==s.length()-1)return true;
        else return false;
    }
};