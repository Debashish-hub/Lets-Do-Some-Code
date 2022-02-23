class Solution {
public:
    static bool comp(vector<int> &x, vector<int> &y){
        if(x[0] == y [0])return x[1] > y[1];

        return x[0] < y[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), comp);
        int maxe = INT_MIN;
        int ans = 0;
        int size = a.size();
        for(int i=size-1; i>=0; i--){
            if(a[i][1] < maxe){
                ans++;
            }
            maxe = max(maxe, a[i][1]);
        }
        return ans;
    }
};