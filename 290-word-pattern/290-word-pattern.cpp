class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string p;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                v.push_back(p);
                p.clear();
            }else{
                p.push_back(s[i]);
            }
        }
        v.push_back(p);
        
        if(pattern.length()!=v.size()){
            return false;
        }
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        for(int i=0;i<pattern.length();i++){
            if(mp1[pattern[i]] == "" && mp2[v[i]] == 0){
                mp1[pattern[i]]=v[i];
                mp2[v[i]]=pattern[i];
            }else if(v[i]!=mp1[pattern[i]] || pattern[i]!=mp2[v[i]]){
                return false;
            }
        }
        return true;
    }
};