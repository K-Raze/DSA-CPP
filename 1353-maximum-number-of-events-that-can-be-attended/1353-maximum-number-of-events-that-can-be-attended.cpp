class Solution {
public:

    // sweep line type 
    // at any time , active time rkh jinki deadline ni ayi abi tk

    int maxEvents(vector<vector<int>>& arr) {
        int n=arr.size();

        int endTime=arr[0][0];
        for(auto& it : arr)
            endTime=max(endTime,it[1]);
        
        vector<vector<int>>state(endTime+1);
        for(auto& it : arr)
            state[it[0]].push_back(it[1]);
        
        priority_queue<int,vector<int>,greater<int>>pq;

        int ans=0;
        for(int t=0;t<=endTime;t++)
        {
            // inactive hata
            while(!pq.empty() && pq.top()<t)
                pq.pop();
            // new active la
            for(int& x : state[t])
                pq.push(x);
            if(!pq.empty())
            {
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};