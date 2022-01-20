class Solution {
public:
    bool possible(vector<int>& piles, int h,int mid, int n)
    {
        int time = 0;
        for(int i = 0; i < n; i++)
           time += (piles[i]  - 1) / mid +1;
        
        return time <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n = piles.size(); 
        int low = 1, high = *max_element(piles.begin(), piles.end());
     
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(possible(piles, h, mid,n))
                high = mid;
            else
                low = mid + 1;
        }
        
        return low;
    }
};