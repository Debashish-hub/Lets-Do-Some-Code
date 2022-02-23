class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min_e = INT_MAX;
        int m = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= min_e){
                min_e = nums[i];
            }else{
                if(m < nums[i]){
                    return true;
                }
                m = nums[i];
            }
        }
        return false;
    }
};