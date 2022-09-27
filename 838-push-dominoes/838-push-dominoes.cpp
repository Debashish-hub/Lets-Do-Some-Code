class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        d="L"+d+"R";
        int l=0,r=1,p1,p2;
        while(l<=(n+1) && r<=(n+1)){
            while(d[r]=='.'){
                r++;
            }
            if(d[l]=='R' && d[r]=='L'){
                p1=l+1,p2=r-1;
                while(p1<p2){
                    d[p1]='R'; d[p2]='L'; p1++; p2--;
                }
            }else if(d[l]=='L' && d[r]=='L'){
                p2=r-1;
                while(p2>l){
                    d[p2]='L'; p2--;
                }
            }else if(d[l]=='R' && d[r]=='R'){
                p1=l+1;
                while(p1<r){
                    d[p1]='R'; p1++;
                }
            }
            l=r;
            r++;
        }
        return d.substr(1,n);
    }
};