class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<v.size();i++){
            auto [s,e]=v[i];
            if(max(start,s)<min(end,e)) return false; //they are overlapping
        }
        v.push_back({start,end}); //we maintain in a sorting order of start point
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */