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

    int take(int idx,int n,vector<vector<int>>& edges)
    {
        dsu_init(n);

        int ans=edges[idx][2];
        unionBySize(edges[idx][0],edges[idx][1]);
        int cnt=1;

        for(int i=0;i<edges.size();i++)
        {
            if(i==idx)
                continue;

            auto& it=edges[i];
            if(ultParent(it[0])!=ultParent(it[1]))
            {
                ans+=it[2];
                unionBySize(it[0],it[1]);
                cnt++;
            }
        }

        return cnt==n-1 ? ans : INT_MAX;
    }

    int notTake(int idx,int n,vector<vector<int>>& edges)
    {
        int ans=0;
        int cnt=0;
        dsu_init(n);

        for(int i=0;i<edges.size();i++)
        {
            if(i==idx)
                continue;

            auto& it=edges[i];
            if(ultParent(it[0])!=ultParent(it[1]))
            {
                ans+=it[2];
                unionBySize(it[0],it[1]);
                cnt++;
            }
        }

        return cnt==n-1 ? ans : INT_MAX;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++)
            edges[i].push_back(i);

        sort(edges.begin(),edges.end(),[&](const auto& a,const auto& b){
            return a[2]<b[2];
        });

        vector<int>critical,pseudo;

        int mst=0;
        dsu_init(n);

        for(auto& it : edges)
            if(ultParent(it[0])!=ultParent(it[1]))
            {
                mst+=it[2];
                unionBySize(it[0],it[1]);
            }

        for(int i=0;i<edges.size();i++)
        {
            int tak=take(i,n,edges);
            int skip=notTake(i,n,edges);

            if(skip>mst)
                critical.push_back(edges[i][3]);
            else if(tak==mst)
                pseudo.push_back(edges[i][3]);
        }

        vector<vector<int>> ans;
        ans.push_back(critical);
        ans.push_back(pseudo);
        return ans;
    }
};