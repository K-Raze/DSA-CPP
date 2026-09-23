class Solution {
public:

    vector<vector<int>>adj;

    double ans;

    void dfs(int x,int par,double p,int t,int tar)
    {
        if(!t)
        {
            if(x==tar)
                ans=p;
            return;
        }
        int c=0;
        for(int& y : adj[x])
            if(y!=par)
                c++;
        if(!c && t)
            dfs(x,par,p,t-1,tar);
        double np=p*(1.0/(double(c)));
        for(int& y : adj[x])
            if(y!=par)
                dfs(y,x,np,t-1,tar);
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        ans=0.0;
        adj.assign(n,{});
        target--;
        for(auto& it : edges)
        {
            it[0]--;
            it[1]--;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1,1.0,t,target);
        return ans;
    }
};