class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int> &a, vector<int> &b){ 
            return a[1] > b[1]; 
        });
        int ans = 0;
        for(int i=0; i<boxTypes.size(); i++){
            if(truckSize == 0) 
                return ans;
            if(truckSize < boxTypes[i][0]){
                ans += truckSize * boxTypes[i][1];
                return ans;
            }
            else{
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
        }
        return ans;
    }
};