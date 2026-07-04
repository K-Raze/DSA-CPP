class Solution {
public:

    vector<vector<int>>adj;

    void dfs(int x,vector<bool>& vis)
    {
        vis[x]=1;
        for(int& y : adj[x])
            if(!vis[y])
                dfs(y,vis);
    }

    int minScore(int n, vector<vector<int>>& roads) {
        adj.resize(n);
        for(auto& it : roads)
        {
            it[0]--;
            it[1]--;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,0);
        dfs(0,vis);
        int ans=INT_MAX;
        for(auto& it : roads)
            if(vis[it[0]] && vis[it[1]])
                ans=min(ans,it[2]);
        return ans;
    }
};