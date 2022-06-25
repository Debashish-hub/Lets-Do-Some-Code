class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() <= 2) return true;
		// Condition to check if the last element is smaller than second last element.
        if(nums[nums.size() - 1] < nums[nums.size() - 2]) nums[nums.size() - 1] = nums[nums.size() - 2];
        else
        {
            for(int i = nums.size() - 2;i > 0;i--)
            {
                if(nums[i] <  nums[i - 1])
                {
                    if(nums[i - 1] > nums[i + 1])  nums[i - 1] = nums[i];
                    else nums[i] = nums[i - 1];
                    break;
                }
            }
        }
        for(int i = 0;i < nums.size() - 1;i++)
        {
            if(nums[i] > nums[i + 1]) return false;
        }
        return true;
    }
};