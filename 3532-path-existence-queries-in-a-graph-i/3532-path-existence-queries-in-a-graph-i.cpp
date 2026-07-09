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

    vector<bool> pathExistenceQueries(int n, vector<int>& arr, int maxDiff, vector<vector<int>>& queries) {
        dsu_init(n);
        {
            int i=0;
            while(i<n)
            {
                if(i-1>=0 && arr[i]-arr[i-1]<=maxDiff)
                    unionBySize(i,i-1);

                int ni=upper_bound(arr.begin(),arr.end(),arr[i]+maxDiff)-arr.begin()-1;
                for(int j=i+1;j<=ni;j++)
                    unionBySize(i,j);
                i=ni+1;
            }
        }
        vector<bool>ans;
        for(auto& it : queries)
        {
            if(ultParent(it[0])==ultParent(it[1]))
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};