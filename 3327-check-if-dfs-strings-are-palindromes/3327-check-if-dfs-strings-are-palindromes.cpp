using ll=long long;
using pll=pair<ll,ll>;
using node=tuple<ll,pll,pll>;
class Solution {
public:

    const ll m1 = 1000000007;
    const ll m2 = 1000000009;
    const ll b1 = 911382323;
    const ll b2 = 972663749;
    vector<ll>p1,p2;

    pll insert(pll h1,pll h2,int len)
    {
        pll ans;
        ans.first=((h1.first*p1[len])%m1+h2.first)%m1;
        ans.second=((h1.second*p2[len])%m2+h2.second)%m2;
        return ans;
    }
    
    vector<vector<int>>adj;
    vector<bool>ans;
    node dfs(int x,string& s)
    {
        pll hf={0,0};
        pll hr={0,0};
        ll len=0;
        for(int& y : adj[x])
        {
            auto [lc,chf,chr]=dfs(y,s);
            // merge front
            hf=insert(hf,chf,lc);
            // merge rev
            hr=insert(chr,hr,len);
            len+=lc;
        }
        // merge front
        hf=insert(hf,{s[x],s[x]},1);
        // merge rev
        hr=insert({s[x],s[x]},hr,len);
        if(hf==hr)
            ans[x]=1;
        return {len+1,hf,hr};
    }

    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n=parent.size();
        p1.resize(n+1);
        p2.resize(n+1);
        p1[0]=1;
        for(int i=1;i<=n;i++)
            p1[i]=(p1[i-1]*b1)%m1;
        p2[0]=1;
        for(int i=1;i<=n;i++)
            p2[i]=(p2[i-1]*b2)%m2;

        adj.resize(n);
        for(int i=1;i<n;i++)
            adj[parent[i]].push_back(i);
        for(int i=0;i<n;i++)
            sort(adj[i].begin(),adj[i].end());

        ans.assign(n,0);
        dfs(0,s);
        return ans;
    }
};