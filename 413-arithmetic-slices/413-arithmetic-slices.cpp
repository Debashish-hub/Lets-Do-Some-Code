class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return 0;
        }
        int diff = nums[1] - nums[0], ans = 0, c = 0;
        for(int i=1; i<n-1; i++){
            int temp = nums[i+1] - nums[i];
            if(temp == diff){
                c++;
            }else{
                diff = temp;
                c = 0;
            }
            ans += c;
        }
        return ans;
    }
};

