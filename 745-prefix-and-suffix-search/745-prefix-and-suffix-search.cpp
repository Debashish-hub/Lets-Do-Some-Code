typedef long long int LL;
class WordFilter 
{
    public:
    LL mod = 1e9+7;
    LL base = 256;
    unordered_map<int, unordered_map<int, int>> M;
    LL mul(LL a, LL b)
    {
        return (a*b) % mod;
    }
    LL add(LL a, LL b)
    {
        return (a+b) % mod;
    }
    
    WordFilter(vector<string>& words) 
    {
        for(int i = 0; i < words.size(); i++)
        {
            auto &s = words[i];
            int sz = s.size();
            LL prehs = 0;
            for(int j = 0; j < sz; j++)
            { // bug i duplicate ...
                prehs = mul(prehs, base);
                prehs = add(prehs, s[j]-'a'+1);
                LL sufhs = 0;
                for(int k = sz-1; k >= 0; k--)
                {
                    sufhs = mul(sufhs, base);
                    sufhs = add(sufhs, s[k]-'a'+1);
                    M[prehs][sufhs] = i;
                }
            }
        }
    }
    int f(string prefix, string suffix) 
    {
        int prehs = 0, sufhs = 0;
        
        for(int i = 0; i < prefix.size(); i++)
        {
            prehs = mul(prehs, base);
            prehs = add(prehs, prefix[i]-'a'+1);
        }
        
        for(int j = suffix.size()-1; j >= 0; j--)
        {
            sufhs = mul(sufhs, base);
            sufhs = add(sufhs, suffix[j]-'a'+1);
        }
        
        if( M.find(prehs) == M.end() ||
          M[prehs].find(sufhs) == M[prehs].end() )
            return -1;
        return M[prehs][sufhs];
    }
};


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */