class Solution
{
    public:

        bool isValid(int minEdge, vector<vector<pair<int, int>>> &adj, long long k, vector< int > &tSort)
        {
            vector<long long> dis(adj.size(), LLONG_MAX);
            dis[0] = 0;
            for(int u:tSort)
            {
                for(int i=0;i<adj[u].size();i++)
                {
                    int v=adj[u][i].first;
                    int w=adj[u][i].second;
                    if(w>=minEdge && dis[u]!=LLONG_MAX)
                        dis[v]=min(dis[v],dis[u]+w);
                }
            }
            return dis[adj.size()-1] != LLONG_MAX && dis[adj.size()-1] <= k;
        }

    int findMaxPathScore(vector<vector < int>> &edges, vector< bool > &online, long long k)
    {
        if(!edges.size())
            return -1;
        int V = online.size();
        vector<int> inDegree(V, 0);
        int maxEdge = 0, minEdge = edges[0][2];
        vector<vector<pair<int, int>>> adj(V);
       	//making adj matrix
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if (!online[u] || !online[v])
                continue;
            int w = edges[i][2];
            maxEdge = max(maxEdge, w);
            minEdge = min(minEdge, w);
            adj[u].push_back({ v,
                w });
            inDegree[v]++;
        }
       	//topo sort
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (!inDegree[i])
                q.push(i);
        vector<int> tSort;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            tSort.push_back(x);
            for (int i = 0; i < adj[x].size(); i++)
            {
                int y = adj[x][i].first;
                inDegree[y]--;
                if (!inDegree[y])
                    q.push(y);
            }
        }
       	//binary search
        int start = minEdge, end = maxEdge;
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isValid( mid, adj, k, tSort))
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};