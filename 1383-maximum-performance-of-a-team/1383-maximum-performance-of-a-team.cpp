class Solution {
public:
    const int M =1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<pair<int, int>> data (n);
        long sum=0, ans=0;
        int eff, i;
        for(i=0; i<n; ++i) {
            data[i]={speed[i], efficiency[i]};
        }
        sort(data.begin(), data.end(), [](pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second || a.second==b.second && a.first>b.first;
        });
        
        auto cmp=[](pair<int,int>&a,pair<int,int>&b) {
            return a.first>b.first || a.first==b.first && a.second>b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> best(cmp);
        for(i=0; i<k; ++i) {
            auto &a=data[i];
            sum+=a.first;
            eff=a.second;
            best.push(a);
            ans=max(ans, sum*eff);
        }
        // cout<<i<<":"<<ans<<"\n";
        for(; i<n; ++i) {
            auto &b=best.top();
            auto &a=data[i];
            // cout<<a.first<<","<<a.second<<" | "<<b.first<<","<<b.second<<"\n";
            if(a.first >b.first) {
                sum-=b.first;
                sum+=a.first;
                eff=a.second;
                ans=max(ans, sum*eff);
                best.pop();
                best.push(a);
                // cout<<i<<":"<<ans<<"\n";
            }
        }
        return ans%M;
    }
};