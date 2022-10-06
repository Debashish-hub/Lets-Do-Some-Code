class TimeMap {
public:
    unordered_map<string, map<int, string>>mp;
    TimeMap() {
        unordered_map<string, map<int, string>> n;
        mp=n;
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())return "";
        auto it=mp[key].end();
        it--;
        for(it; it!=mp[key].begin(); it--){
            if(it->first<=timestamp)return it->second;
        }
        if(it->first<=timestamp)return it->second;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */