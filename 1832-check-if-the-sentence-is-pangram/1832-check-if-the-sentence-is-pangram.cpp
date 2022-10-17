class Solution {
public:
    bool checkIfPangram(string sentence) {
        int a[26]={0};
        for(char x:sentence)
        {
            a[x-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]==0)
                return 0;
        }
        return 1;
    }
};