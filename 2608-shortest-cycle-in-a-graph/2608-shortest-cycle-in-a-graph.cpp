class Solution {
public:

    int n;
    vector<vector<int>>adj;

    int bfs(int src)
    {
        vector<int>dis(n,-1);
        vector<int>par(n,-1);
        queue<int>q;
        int mc=2e9;
        dis[src]=1;
        q.push(src);

        while(!q.empty())
        {
            int x=q.front();
            q.pop();

            for(int& y : adj[x])
            {
                if(dis[y]!=-1)
                {
                    if(y!=par[x] && x!=par[y])
                        mc=min(mc,dis[y]+dis[x]-1);
                }
                else
                {
                    par[y]=x;
                    dis[y]=1+dis[x];
                    q.push(y);
                }
            }
        }
        return (mc==2e9) ? -1 : mc;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        this->n=n;
        adj.assign(n,{});
        for(auto& it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            int val=bfs(i);
            if(val==-1)
                continue;
            if(ans==-1)
                ans=val;
            else
                ans=min(ans,val);
        }
        return ans;
    }
};