class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = 0, temp = 0, t=0;
        for(int i=0; i<n; i++){
            temp += gas[i] - cost[i];
            if(temp < 0){
                ans += temp;
                temp  = 0;
                t = i+1;
            }
        }
        ans += temp;
        if(ans < 0)return -1;
        return t;
    }
};

