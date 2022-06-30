class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
		sort(nums.begin(), nums.end());
		int res = 0;
		int median = nums[n / 2];
		for(int i = 0; i < n; i++){
			res += abs(nums[i] - median);
		}
		return res;
    }
};