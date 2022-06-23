class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    }
  
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(),courses.end(),comp);
    
        int total_days = 0;
        priority_queue<int> q;
        for(auto &it: courses){
            q.push(it[0]);
            total_days += it[0];
            if (total_days > it[1]) 
                total_days -= q.top(),q.pop();
        }    
        return q.size();
    }
};