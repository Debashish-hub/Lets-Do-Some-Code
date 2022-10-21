class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i,j;
        map<int, int> m;
        j = 0;
        for(i=0;i<n;i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = i;
            }
            else{
                if(abs(m[nums[i]]-i)<=k)
                    return true;
                
                m[nums[i]] = i;
            }
            
        }
        
        return false;
    }
};