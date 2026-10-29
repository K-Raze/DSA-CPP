class FreqStack {
public:

    priority_queue<array<int,3>>pq;
    unordered_map<int,int>cnt;
    int idx;

    FreqStack() {
        cnt.clear();
        while(!pq.empty())
            pq.pop();
        idx=0;
    }
    
    void push(int val) {
        cnt[val]++;
        pq.push({cnt[val],idx,val});
        idx++;
    }
    
    int pop() {
        auto[freq,i,val]=pq.top();
        pq.pop();
        cnt[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */