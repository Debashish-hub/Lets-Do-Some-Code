class MyCalendarThree {
public:
    map<int, int>map;
    int ans=0;
    int book(int start, int end) {
        map[start]++;
        map[end]--;
        int res=0;
        for(auto [k, v]:map){
            res+=v;
            ans=max(ans, res);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */