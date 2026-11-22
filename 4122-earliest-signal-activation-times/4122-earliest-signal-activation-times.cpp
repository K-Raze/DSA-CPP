using ll=long long;
class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& rs) {
        vector<vector<pair<ll,ll>>>adj(n);
        for(auto& it : edges)
            adj[it[0]].push_back({it[1],it[2]});
        
        vector<ll>ans(n,-1);
        ans[0]=0;

        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,
            greater<pair<ll,ll>>>pq;

        rs[0]=1;
        pq.push({0,0});

        while(!pq.empty())
        {
            auto[t,x]=pq.top();
            pq.pop();
            rs[x]--;
            if(!rs[x])
            {
                ans[x]=t;
                for(auto&[y,d] : adj[x])
                    pq.push({t+d,y});
            }
        }
        return ans;
    }
};