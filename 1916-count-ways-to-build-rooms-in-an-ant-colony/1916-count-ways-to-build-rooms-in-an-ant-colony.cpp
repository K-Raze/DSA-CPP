using ll=long long;
const int mod=1e9+7;
class Solution {
public:

    vector<ll>fac,invFac;

    ll modExp(ll b,ll p)
    {
        if(!p)
            return 1;
        ll temp=modExp(b,p/2);
        temp=(temp*temp)%mod;
        if(p&1)
            temp=(temp*b)%mod;
        return temp;
    }

    void init(ll n)
    {
        fac.resize(n+1);
        invFac.resize(n+1);
        fac[0]=1;
        invFac[0]=1;
        for(int i=1;i<=n;i++)
            fac[i]=(fac[i-1]*i)%mod;
        invFac[n]=modExp(fac[n],mod-2);
        for(int i=n-1;i>=1;i--)
            invFac[i]=((i+1)*invFac[i+1])%mod;
    }


    vector<vector<int>>adj;
    vector<ll>subSize;

    void initDfs(int x)
    {
        subSize[x]=1;
        for(int& y : adj[x])
        {
            initDfs(y);
            subSize[x]+=subSize[y];
        }
    }

    ll solve(int x)
    {
        ll ans=1;
        ll total=0;
        for(int& y : adj[x])
        {
            total+=subSize[y];
            ans=(ans*invFac[subSize[y]])%mod;
            ans=(ans*solve(y))%mod;
        }
        ans=(ans*fac[total])%mod;
        return ans;
    }

    int waysToBuildRooms(vector<int>& prevRoom) {
        int n=prevRoom.size();
        init(n+1);
        adj.resize(n);
        subSize.resize(n);
        for(int v=0;v<n;v++)
        {
            int u=prevRoom[v];
            if(u==-1)
                continue;
            adj[u].push_back(v);   
        }
        initDfs(0);
        return solve(0);
    }
};