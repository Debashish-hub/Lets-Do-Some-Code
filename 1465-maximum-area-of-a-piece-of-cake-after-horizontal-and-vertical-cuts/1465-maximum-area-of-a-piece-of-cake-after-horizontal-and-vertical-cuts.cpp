class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long mod=1000000007;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        return long(fun(horizontalCuts,h))%mod *long(fun(verticalCuts,w))%mod;
    }
     int fun(vector<int>v,int num)
    {
        int ans=0;
        for(int i=1;i<v.size();i++)
            ans=fmax(ans,v[i]-v[i-1]);
        ans=fmax(ans,v[0]);
        ans=fmax(ans,num-v[v.size()-1]);
        return ans;
    }
};