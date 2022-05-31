class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> b(nums.size(), false);
        b[0] = true;
        for(int i=0; i<nums.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(b[j]==true && (j + nums[j] >= i)){
                    b[i] = true;
                    break;
                }
            }
        }
        return b[nums.size() - 1];
    }
};


        