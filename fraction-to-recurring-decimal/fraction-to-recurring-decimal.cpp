class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        
        int sign = 0;
        
        if(numerator < 0 and denominator < 0)
            sign = 0;
        else if(numerator < 0 and denominator > 0 || numerator > 0 and denominator < 0 )
            sign = 1;
        
        long n = abs(numerator);
        long d = abs(denominator);
        
        long q = (n / d);
        long r = (n % d);
        ans += to_string(q);
        
        if(r == 0){
            if(sign == 1)
                ans.insert(ans.begin(),'-');
            return ans;
        }
        else{
            ans += '.';
            unordered_map<long, int> mp; 
            while(r != 0){
                if(mp.find(r) != mp.end()){
                    int len = mp[r];
                    ans.insert(ans.begin()+len, '(');
                    ans.push_back(')');
                    break;
                }
                else{
                    mp.insert({r,ans.length()});
                }
                r = r * 10;
                q = (r/d);
                r = r % d;
                ans += to_string(q);
            }
        }
        if(sign == 1)
            ans.insert(ans.begin(),'-');
        return ans;
    }
};