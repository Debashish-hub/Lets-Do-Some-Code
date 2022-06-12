class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
        int i = 0;
        int j = 0;
        unordered_set<int> set;
        set.insert(nums[i]);
        int ans = nums[i];
        int sum = nums[i];
        
        while(j < nums.size()-1 && i <= j){
            int next = nums[++j];
            while(set.count(next) > 0){
                sum -= nums[i];
                set.erase(nums[i]);
                i++;
            }
            
            set.insert(next);
            sum += next;
            ans = max(ans, sum);
        }

        return ans;
    }
};