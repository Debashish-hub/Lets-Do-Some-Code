class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        unordered_map<int,int>mp;
        // store all possible sum value of two element from nums1 and nums2 in a map 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[nums1[i]+nums2[j]]++;
            }
        }
        int ans=0;
        // now finding all possible sum value of two element from nums3 and nums4 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               int curr=nums3[i]+nums4[j];
                //for total sum to be zero negative of this sum should be present in the map and we will also take care of no of times it is present
                curr*=-1;
                if(mp[curr]){
                   ans+=mp[curr];  
                }
            }
        }
        return ans;
    }
};