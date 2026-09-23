class Solution {
public:

    class DSU
    {
        vector<int>par,sz;

        public:

        DSU(int n)
        {
            par.resize(n);
            iota(par.begin(),par.end(),0);
            sz.resize(n,1);
        }

        int ultParent(int x)
        {
            if(par[x]==x)
                return x;
            return par[x]=ultParent(par[x]);
        }

        void unite(int a,int b)
        {
            a=ultParent(a);
            b=ultParent(b);
            if(a==b)
                return;
            if(sz[a]<sz[b])
                swap(a,b);
            sz[a]+=sz[b];
            par[b]=a;
        }

    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int edgeUse=0;
        DSU alice(n),bob(n);

        // type 3
        for(auto& it : edges)
            if(it[0]==3)
            {
                it[1]--;
                it[2]--;
                if(alice.ultParent(it[1])!=alice.ultParent(it[2])
                    || bob.ultParent(it[1])!=bob.ultParent(it[2]))
                {
                    edgeUse++;
                    alice.unite(it[1],it[2]);
                    bob.unite(it[1],it[2]);
                }
            }

        for(auto& it : edges)
            if(it[0]!=3)
            {
                it[1]--;
                it[2]--;
                if(it[0]==1 && alice.ultParent(it[1])!=alice.ultParent(it[2]))
                {
                    edgeUse++;
                    alice.unite(it[1],it[2]);
                }
                if(it[0]==2 && bob.ultParent(it[1])!=bob.ultParent(it[2]))
                {
                    edgeUse++;
                    bob.unite(it[1],it[2]);
                }
            }

        // alice check
        {
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                // cout<<alice.ultParent(i)<<" ";
                if(alice.ultParent(i)==i)
                    cnt++;
            }
            if(cnt>1)
                return -1;
        }
        // bob
        {
            int cnt=0;
            for(int i=0;i<n;i++)
                if(bob.ultParent(i)==i)
                    cnt++;
            if(cnt>1)
                return -1;
        }
        return edges.size()-edgeUse;
    }
};