class Solution {
public:

    // server empty -> req drop
    // (i+k)available assign it to it

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {    
        set<int>freeServer;
        priority_queue<pair<int,int>,vector<pair<int,int>>,
                greater<pair<int,int>>>pq; // end time and server name
        
        vector<int>comp(k,0);
        for(int i=0;i<k;i++)
            freeServer.insert(i);

        for(int i=0;i<load.size();i++)
        {
            int time=arrival[i];
            while(!pq.empty() && time>=pq.top().first)
            {
                freeServer.insert(pq.top().second);
                pq.pop();
            }
            if(freeServer.empty())
                continue;
            int idx=i%k;
            auto it=freeServer.lower_bound(idx);
            if(it!=freeServer.end())
            {
                int sid=*it;
                freeServer.erase(sid);
                comp[sid]++;
                pq.push({time+load[i],sid});
            }
            else
            {
                int sid=*freeServer.begin();
                freeServer.erase(sid);
                comp[sid]++;
                pq.push({time+load[i],sid});
            }
        }
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            // cout<<comp[i]<<" ";
            if(ans.empty())
                ans.push_back(i);
            else if(comp[ans.front()]<comp[i])
            {
                ans.clear();
                ans.push_back(i);
            }
            else if(comp[ans.front()]==comp[i])
                ans.push_back(i);
        }
        return ans;
    }
};