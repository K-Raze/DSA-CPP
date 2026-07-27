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
    int longestConsecutive(vector<int>& arr) {
        if(!arr.size())
            return 0;
        unordered_map<int,int>mpIdx;
        {
            unordered_set<int>st;
            for(int& x : arr)
                st.insert(x);
            int i=0;
            for(int x : st)
                mpIdx[x]=i++;
            dsu_init(i);
        }
        for(int&x : arr)
        {
            if(mpIdx.find(x-1)!=mpIdx.end())
                unionBySize(mpIdx[x-1],mpIdx[x]);
            if(mpIdx.find(x+1)!=mpIdx.end())
                unionBySize(mpIdx[x+1],mpIdx[x]);
        }
        int ans=1;
        for(int& x : arr)
            ans=max(ans,size_dsu[ultParent(mpIdx[x])]);
        return ans;
    }
};