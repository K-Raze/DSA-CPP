class Solution {
public:

    int dfs(int x,vector<int>& edges,vector<bool>& vis)
    {
        vis[x]=1;
        int ans=1;
        int y=edges[x];
        if(vis[y])
            return ans;
        return ans+dfs(y,edges,vis);
    }

    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>inDeg(n,0);
        for(int u=0;u<n;u++)
        {
            int v=edges[u];
            if(v==-1)
                continue;
            inDeg[v]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++)
            if(!inDeg[i])
                q.push(i);
        
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            int y=edges[x];
            if(y==-1)
                continue;
            inDeg[y]--;
            if(!inDeg[y])
                q.push(y);
        }

        int ans=-1;
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++)
            if(inDeg[i] && !vis[i])
                ans=max(ans,dfs(i,edges,vis));
        return ans; 
    }
};