using ll=long long;
using pll=pair<ll,ll>;
class Solution {
public:

    vector<vector<int>>adj;
    vector<int>group;

    ll ans;

    inline void merge(array<pll,20>& a,const array<pll,20>& b)
    {
        for(int i=0;i<20;i++)
        {
            a[i].first+=b[i].first;
            a[i].second+=b[i].second;
        }
    }

    // cnt,disSum
    array<pll,20> dfs(int x,int par)
    {
        array<pll,20> total{};
        total[group[x]].first=1;
        vector<array<pll,20>>arr;
        for(int& y : adj[x])
            if(y!=par)
            {
                auto temp=dfs(y,x);
                for(auto&[a,b] : temp)
                    b+=a;
                arr.push_back(temp);
                merge(total,temp);
            }
        for(auto& temp : arr)
            for(int i=0;i<20;i++)
                ans+=1LL*(total[i].first-temp[i].first)*temp[i].second;
        return total;
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& grp) {
        group=grp;
        for(int& x : group)
            x--;
        ans=0;
        adj.resize(n);
        for(auto& it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1);
        return ans;
    }
};