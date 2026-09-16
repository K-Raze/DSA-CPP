const int del=1e6;
class Solution {
public:
    
    // 1 2 7 - 30 - 3
    // \ | /    |
    //   20     6
    // bfs
    // dummy node

    int numBusesToDestination(vector<vector<int>>& routes, int src, int tar) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<routes.size();i++)
            for(int u : routes[i])
            {
                adj[i+del].push_back(u);
                adj[u].push_back(i+del);
            }
        queue<int>q;
        unordered_map<int,bool>vis;
        q.push(src);
        int ans=1;
        while(!q.empty())
        {
            int k=q.size();
            while(k--)
            {
                int x=q.front();
                q.pop();
                if(x==tar)
                    return ans/2;
                for(int& y : adj[x])
                    if(!vis[y])
                    {
                        vis[y]=1;
                        q.push(y);
                    }
            }
            ans++;
        }
        return -1;
    }
};