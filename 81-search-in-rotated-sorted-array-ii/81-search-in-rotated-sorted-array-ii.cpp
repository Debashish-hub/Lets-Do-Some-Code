class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low < high){
            int mid = (low + high)/2;
            
            if(low == mid){
                if(nums[high] == target)
                    low++;
                break;
            }
            if(nums[mid] < nums[high]){
                if(target > nums[mid] && target <= nums[high])
                    low = mid;
                else
                    high = mid;
            }else if(nums[low] < nums[mid]){
                if(target >= nums[low] && target <= nums[mid])
                    high = mid;
                else
                    low = mid;
            }else{
                while(low < mid && nums[low] == nums[low+1])
                    low++;
                while(high > mid && nums[high] == nums[high-1])
                    high--;
            }
        }
        return nums[low] == target;
    }
};