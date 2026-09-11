class SnapshotArray {
public:

    int sp;
    vector<vector<pair<int,int>>>arr; // snap - val
    vector<int>curr;
    set<int>changeQ;

    SnapshotArray(int len) {
        arr.resize(len,{{-1,0}});
        curr.resize(len,0);
        sp=0;
    }
    
    void set(int idx, int val) {
        changeQ.insert(idx);
        curr[idx]=val;
    }
    
    int snap() {
        
        while(!changeQ.empty())
        {
            int idx=*changeQ.begin();
            changeQ.erase(idx);
            arr[idx].push_back({sp,curr[idx]});
        }
        sp++;
        return sp-1;
    }
    
    int get(int i, int s) { // ub-1;
        auto& vec=arr[i];
        int idx=upper_bound(vec.begin(),vec.end(),make_pair(s+1,-2))-vec.begin()-1;
        return vec[idx].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */