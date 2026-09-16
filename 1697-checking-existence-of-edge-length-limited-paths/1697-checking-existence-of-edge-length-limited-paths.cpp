class Solution {
public:

    // ----------------------- DSU ----------------------
    vector<int> parent_dsu, size_dsu;

    void dsu_init(int n)
    {
        parent_dsu.resize(n);
        size_dsu.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent_dsu[i] = i;
    }

    int ultParent(int x) { return x == parent_dsu[x] ? x : parent_dsu[x] = ultParent(parent_dsu[x]); }

    void unionBySize(int a, int b)
    {
        a = ultParent(a);
        b = ultParent(b);
        if (a == b)
            return;
        if (size_dsu[a] < size_dsu[b])
            swap(a, b);
        parent_dsu[b] = a;
        size_dsu[a] += size_dsu[b];
    }
    // --------------------------------------------------

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        sort(edges.begin(),edges.end(),[&](const auto& a,const auto& b){
            return a[2]<b[2];
        });
        for(int i=0;i<queries.size();i++)
            queries[i].push_back(i);
        sort(queries.begin(),queries.end(),[&](const auto& a,const auto& b){
            return a[2]<b[2];
        });

        // up   que
        // down edges
        int u=0,d=0;
        dsu_init(n);
        vector<bool>ans(queries.size(),0);
        while(u<queries.size())
        {
            while(d<edges.size() && edges[d][2]<queries[u][2])
            {
                unionBySize(edges[d][0],edges[d][1]);
                d++;
            }
            if(ultParent(queries[u][0])==ultParent(queries[u][1]))
                ans[queries[u][3]]=1;
            u++;
        }
        return ans;
    }
};