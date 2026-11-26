using ll=long long;
class Solution {
public:

    vector<vector<pair<int,ll>>>adj,revAdj;

    vector<ll>dijkstra(int src,int n,vector<vector<pair<int,ll>>>& graph)
    {
        vector<ll>dis(n,LLONG_MAX);
        dis[src]=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,src});

        while(!pq.empty())
        {
            auto[d,x] = pq.top();
            pq.pop();

            if(dis[x]!=d)
                continue;
            
            for(auto&[y,w] : graph[x])
                if(d+w<dis[y])
                {
                    dis[y]=d+w;
                    pq.push({d+w,y});
                }
        }

        return dis;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        adj.resize(n);
        revAdj.resize(n);
        for(auto& it : edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            revAdj[it[1]].push_back({it[0],it[2]});
        }

        vector<ll>dis1=dijkstra(src1,n,adj);
        vector<ll>dis2=dijkstra(src2,n,adj);
        vector<ll>dis3=dijkstra(dest,n,revAdj);

        ll ans=LLONG_MAX;
        for(int i=0;i<n;i++)
            if(dis1[i]!=LLONG_MAX && dis2[i]!=LLONG_MAX && dis3[i]!=LLONG_MAX)
                ans=min(ans,dis1[i]+dis2[i]+dis3[i]);

        return ans==LLONG_MAX ? -1 : ans;
    }
};