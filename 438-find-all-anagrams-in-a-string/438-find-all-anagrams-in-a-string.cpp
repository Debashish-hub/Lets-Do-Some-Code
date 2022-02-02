class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        if(s.length()<p.length()) return ans;
        
        vector<int> hash(26,0); //pattern hash 
        vector<int> strhas(26,0); // string hash
        
        int k=p.length();
        int n=s.length();
        int count=0;
        
        // I gonna store 1st kth window elements into specfic hashs
        for(int i=0;i<p.length();i++)
        {
            hash[p[i]-'a']++;
            strhas[s[i]-'a']++;
        }
        
        if(hash==strhas) ans.push_back(0);
        
        // Now,I begin traversal from kth index
        for(int i=k;i<s.length();i++)
        {
            strhas[s[i]-'a']++; // adding 1 element into hash
            count++;
			
            if(count==1) // CHECKING ONE BY ONE -> THROUGH ONE PASS
            {
                strhas[s[i-k]-'a']--; // decrementing 1 most early added element count from STRHASH 
                if(hash==strhas) ans.push_back(i-k+1);  // ADDING STARTING INDEX OF ANAGRAM INTO RES vector
                count=0; 
            }
        }
        return ans;
    }
};