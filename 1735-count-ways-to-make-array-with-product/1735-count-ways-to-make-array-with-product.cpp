const int mod=1e9+7;
using ll=long long;
class Solution {
public:

    // 2 3 
    // 2 
    // n+k-1 C k-1 
    // // simple stars and bars h bc 

    ll modExp(ll b,ll p)
    {
        if(!p)
            return 1;
        
        ll ans=modExp(b,p/2);
        ans=(ans*ans)%mod;

        if(p&1)
            ans=(ans*b)%mod;
        
        return ans;
    }

    vector<ll>fac,invFac;

    void init(ll n)
    {
        fac.resize(n+1);
        invFac.resize(n+1);

        fac[0]=1;
        for(int i=1;i<=n;i++)
            fac[i]=(fac[i-1]*i)%mod;

        invFac[n]=modExp(fac[n],mod-2);
        for(int i=n-1;i>=0;i--)
            invFac[i]=(invFac[i+1]*(i+1))%mod;
    }

    inline ll nCr(ll n,ll r)
    {
        return ((fac[n]*invFac[r])%mod * invFac[n-r])%mod;
    }

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

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        sieve(1e4+5);
        init(3e4);
        vector<int>ans;
        for(auto& it : queries)
        {
            ll n=it[0],val=it[1];
            ll meow=1;
            while(val>1)
            {
                ll cnt=0;
                ll div=spf[val];
                while(val%div==0)
                {
                    cnt++;
                    val/=div;
                }
                meow=(meow*nCr(n+cnt-1,cnt))%mod;
            }
            ans.push_back(meow);
        }
        return ans;
    }
};