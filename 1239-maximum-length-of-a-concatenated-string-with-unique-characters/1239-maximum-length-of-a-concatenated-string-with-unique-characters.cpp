class Solution {
public:
    bool unique(string str)
    {
        if(str.length()>26)
            return false;
        int freq[26]={0};
        string s=str;
        for(char ch:s)
        {
            freq[ch-'a']++;
            if(freq[ch-'a']>1)
                return false;
        }
        return true;
    }
    int max(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    int maxLength(vector<string>& arr) {
        vector<string> anslist;
        int maxf=0;
        anslist.push_back("");
        for(string str:arr)
        {
            if(!unique(str))
                continue;
            vector<string> newans;
            for(string c:anslist)
            {
                string temp=c+str;
                if(unique(temp))
                {
                    newans.push_back(temp);
                    maxf=max(maxf,temp.length());
                }
            }
            anslist.insert(anslist.end(),newans.begin(),newans.end());
            
        }
        return maxf;
    }
};