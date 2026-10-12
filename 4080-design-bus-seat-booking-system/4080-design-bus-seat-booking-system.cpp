class BusBooking {
public:

    int totalBooked;
    vector<vector<pair<bool,int>>>isBook;
    int totalTime;

    BusBooking(int n) {
        totalBooked=0;
        totalTime=0;
        isBook=vector<vector<pair<bool,int>>>(n,
            vector<pair<bool,int>>(4,{0,0}));
    }
    
    void toggle(string seat) {
        int c=seat[0]-'A';
        int r=stoi(seat.substr(1));
        r--;
        if(isBook[r][c].first)
        {
            totalBooked--;
            totalTime-=isBook[r][c].second;
            isBook[r][c]={0,0};
        }
        else
        {
            totalBooked++;
            int t=1;
            if((c==0 && isBook[r][c+1].first) || 
                (c==3 && isBook[r][c-1].first))
                    t=3;
            isBook[r][c]={1,t};
            totalTime+=t;
        }
    }
    
    int getTotalTime() {
        return totalTime;
    }
    
    int getMinTime() {
        return totalBooked;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */