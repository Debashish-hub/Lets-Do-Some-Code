class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x,y;
      sort(nums.begin(),nums.end());
      int n=nums.size();
      vector <int> v(n+1);
      for(int i=1;i<n+1;i++){
          v[nums[i-1]]++;
      }
        
      for(int i=1;i<=n;i++){
          if(v[i]==2)
             x=i;
          else if(v[i]==0)
             y=i;
      } 
      return {x,y};
    }
};