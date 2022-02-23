class Solution {
public:
    int maxDistToClosest(vector<int>& a) {
        int start = 0, i = 0;
        int ans = 0;
        while(a[i] == 0){
            start++;
            i++;
        }
        int t = start;
        int size = a.size();
        while(i < size){
            if(a[i] == 0){
                t++;
            }else{
                ans = max(ans, t);
                t = 0;
            }
            i++;
        }
        ans = ans % 2 == 0 ? ans/2 : ans/2 + 1;
        return max(ans, max(t, start));
    }
};