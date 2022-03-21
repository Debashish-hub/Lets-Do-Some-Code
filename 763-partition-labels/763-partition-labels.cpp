class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26]={0}, n=s.size();   
         vector<int> res;

         for(int i=0; i<size(s); ++i){ 
             last[s[i]-'a']=i;
         }
        
         for(int l=-1, r=0, curEnd=0; r<n ; ++r){
             curEnd = max(curEnd, last[s[r]-'a']);

             if(curEnd==r){
                 res.push_back(r-l); 
                 l=r; 
             }
         }

         return res;
    }
};