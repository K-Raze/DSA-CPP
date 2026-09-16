class Solution {
public:

    // L ques 

    // ----------------------- DSU ----------------------
    vector<int> parent_dsu, size_dsu;
    const int del=1e4+1;
    void dsu_init()
    {
        parent_dsu.resize(20005);
        size_dsu.assign(20005, 1);
        for (int i = 0; i < 20005; i++)
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

    vector<bool> areConnected(int n, int t, vector<vector<int>>& queries) {
        dsu_init();
        for(int val=1;val<=n;val++) 
            for(int i=1;i*i<=val;i++)
                if(val%i==0)
                {
                    int a=i;
                    int b=val/i;
                    if(a>t)
                        unionBySize(a+del,val);
                    if(b>t)
                        unionBySize(b+del,val);
                }
        vector<bool>ans;
        for(auto& it : queries)
            ans.push_back(ultParent(it[0])==ultParent(it[1]));
        return ans;
    }
};