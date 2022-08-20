class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int nowpos=startFuel;
        int counter=0,p=0;
        priority_queue<int>pq;
        while(1){
            while(p<(int)stations.size()&&stations[p][0]<=nowpos){
                pq.push(stations[p][1]);
                p++;
            }
            if(nowpos>=target)return counter;
            if(pq.empty())return -1;
            nowpos+=pq.top();pq.pop();
            counter++;
        }
    }
};