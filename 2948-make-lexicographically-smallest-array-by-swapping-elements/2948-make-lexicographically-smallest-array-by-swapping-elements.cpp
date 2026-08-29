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
    // 1 3 5 8 9

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int lim) {
        int n=nums.size();

        dsu_init(n);

        vector<pair<int,int>>arr(n);
        {
            for(int i=0;i<n;i++)
                arr[i]={nums[i],i};
            sort(arr.begin(),arr.end());
        }

        int r=0;
        for(int l=0;l<n;l++)
        {
            while(r<n && arr[r].first-arr[l].first<=lim)
                r++;
            unionBySize(arr[r-1].second,arr[l].second);
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            int p=ultParent(i);
            mp[p].push_back(nums[i]);
        }
        for(auto&[a,b] : mp)
            sort(b.rbegin(),b.rend());
        for(int i=0;i<n;i++)
        {
            auto& vec=mp[ultParent(i)];
            nums[i]=vec.back();
            vec.pop_back();
        }
        return nums;
    }
};