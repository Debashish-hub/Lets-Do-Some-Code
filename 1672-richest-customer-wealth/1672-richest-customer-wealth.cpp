class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int w = 0, max = 0;
        for(int i=0; i<accounts.size(); i++)
        {
            w =0;
            for(int j= 0; j<accounts[i].size(); j++)
            {
                w = w + accounts[i][j];
                
            }
            if(max <= w)
                max = w;
            else
                continue;
            
        }
        return max;
    }
};