class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size(), res = 0, i;
        if(len>0)
        {
            vector<int> number(len, 0); 
            number[0] = 1; 
            for(i=1; i<len; i++) 
                number[i] = ratings[i] > ratings[i-1] ? number[i-1] + 1 : 1;

            for(i = len-2, res = number[len-1]; i >= 0 ; i--)
            {
                if( (ratings[i] > ratings[i+1]) && number[i] < (number[i+1] + 1) ) number[i] = number[i+1] + 1;
                res += number[i];
            }
        }
        return res;
    }
};