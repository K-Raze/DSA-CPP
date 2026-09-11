class Solution {
public:
    int minRefuelStops(int tar, int fuel, vector<vector<int>>& station) {
        priority_queue<int>pq;
        int ans=0;
        int lastPos=0;
        for(auto&it : station)
        {
            int pos=it[0],cap=it[1];
            int diff=pos-lastPos;
            while(fuel<diff && !pq.empty())
            {
                fuel+=pq.top();
                ans++;
                pq.pop();
            }
            if(fuel<diff)
                return -1;
            fuel-=diff;
            pq.push(cap);
            lastPos=pos;
        }
        int diff=tar-lastPos;
        while(fuel<diff && !pq.empty())
        {
            fuel+=pq.top();
            ans++;
            pq.pop();
        }
        if(fuel<diff)
            return -1;
        return ans;
    }
};