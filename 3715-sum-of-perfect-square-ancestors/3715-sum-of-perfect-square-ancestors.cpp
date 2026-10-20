using ll=long long;
class Solution {
public:

    vector<ll>spf;

    void sieve(ll n)
    {
        spf.resize(n+1,-1);
        spf[1]=1;
        for(ll i=2;i<=n;i++)
            if(spf[i]==-1)
            {
                spf[i]=i;
                for(ll j=i*i;j<=n;j+=i)
                    if(spf[j]==-1)
                        spf[j]=i;
            }
    }

    vector<vector<int>>adj;
    unordered_map<ll,ll>mask;
    
    ll solve(int x,int par,unordered_map<ll,unordered_multiset<ll>>& mp,
        vector<int>& arr)
    {
        ll ans=0;
        auto& st=mp[mask[arr[x]]];
        ans+=st.size();

        st.insert(arr[x]);

        for(int& y : adj[x])
            if(y!=par)
                ans+=solve(y,x,mp,arr);
        
        auto it =st.find(arr[x]);
        st.erase(it);
        return ans;
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& arr) {
        
        ll me=*max_element(arr.begin(),arr.end())+5;
        sieve(me);
        adj.assign(n,{});
        for(auto& it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        mask.clear();
        {
            unordered_set<ll>st(arr.begin(),arr.end());
            for(int x : st)
            {
                ll v=x;
                ll m=1;
                while(x>1)
                {
                    ll cnt=0;
                    ll div=spf[x];
                    while(x%div==0)
                    {
                        cnt++;
                        x/=div;
                    }
                    if(cnt&1)
                        m*=div;
                }
                mask[v]=m;
            }
        }
        unordered_map<ll,unordered_multiset<ll>>mp;
        return solve(0,-1,mp,arr);
    }
};