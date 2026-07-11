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

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        dsu_init(n);
        vector<int>eCnt(n,0);
        for(auto& it : edges)
        {
            unionBySize(it[0],it[1]);
            eCnt[it[0]]++;
            eCnt[it[1]]++;
        }
        vector<bool>fraud(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int p=ultParent(i);
            if(fraud[p])
                continue;
            if(eCnt[i]!=size_dsu[p]-1)
                fraud[p]=1;
        }
        for(int i=0;i<n;i++)
            if(i==ultParent(i) && !fraud[i])
                ans++;
        return ans;
    }
};