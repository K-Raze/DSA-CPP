class TimeMap {
public:

    // key ->time,value // its like a locker 
    unordered_map<string,set<pair<int,string>>>keyTimeVal;

    TimeMap() {
        keyTimeVal.clear();
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeVal[key].insert({timestamp,value});
    }
    
    string get(string key, int t) { // ub-1
        auto& st=keyTimeVal[key];
        auto it=st.upper_bound({t+1,""});
        if(it==st.begin())
            return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */