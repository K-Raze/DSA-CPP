class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>>adj(n);
        vector<int>deg(n,0);
        for(auto& it : edges)
        {
            it[0]--;
            it[1]--;
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
            deg[it[0]]++;
            deg[it[1]]++;
        }

        int ans=2e9;

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            if(adj[i].find(j)!=adj[i].end())
                for(int k=j+1;k<n;k++)
                    if(adj[i].find(k)!=adj[i].end()
                        && adj[j].find(k)!=adj[j].end())
                            ans=min(ans,deg[i]+deg[j]+deg[k]-6);
        if(ans==2e9)
            return -1;
        return ans;
    }
};