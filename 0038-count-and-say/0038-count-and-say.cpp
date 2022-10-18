class Solution {
public:
    string countAndSay(int n) {
        string pre="1*",final=""; 
        for(int i=2;i<=n;++i){ 
            int count=0;
            for(int j=0;j<pre.size()-1;++j){ 
                if(pre[j]==pre[j+1])
                count++; 
                else{
                    count++;
                    if(count)
                        final+=to_string(count)+pre[j]; 
                    count=0;
                }
            }
            pre=final+'*';
            final="";
        } 
        int m=pre.size();
        return pre.substr(0,m-1);
    }
};