class Solution {
public:
    int minSetSize(vector<int>& arr) {
         vector<int> hm(100001, 0);
        int n = arr.size(), res = 0, count = 0;
        for(int i = 0; i < n; i++) hm[arr[i]]++;
        vector<int> vp;
        for(int i = 0; i < n; i++) {
            if(hm[arr[i]]) {
                vp.push_back(hm[arr[i]]);
                hm[arr[i]] = 0;
            }
        }
        sort(vp.begin(), vp.end(), [](const auto &a, const auto &b) {
            return a > b;
        });
        for(auto &p : vp) {
            count += p;
            res++;
            if(count >= n/2) return res;
        }
        return res;
    }
};