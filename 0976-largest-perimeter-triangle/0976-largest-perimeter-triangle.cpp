class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ma=-1;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]+nums[i+1]>nums[i+2])
            {
                ma=max(ma,nums[i]+nums[i+1]+nums[i+2]);
            }
        }
            if(ma<0) return 0;
        return ma;
    }
};