using ll=long long;
const int mod=1e9+7;
class Solution {
public:

    // 3 4 5 1 2
    // 1 2 | 4 5 
    // 3+2+1
    // 4 5 1 2 
    // 4 1 5 2 
    // 4 1 2 5
    // 1 4 5 2  
    // 1 4 2 5
    // 1 2 4 5  
    
    vector<ll>fac;
    vector<ll>invFac;

    ll modExp(ll b,ll p)
    {
        if(!p)
            return 1;
        ll ans=modExp(b,p/2);
        ans=(ans*ans)%mod;
        if(p&1)
            ans=(b*ans)%mod;
        return ans;
    }

    void init(int n)
    {
        fac.resize(n+1);
        invFac.resize(n+1);
        fac[0]=1;
        for(int i=1;i<=n;i++)
            fac[i]=(fac[i-1]*i)%mod;
        
        // (1/n!)%mod => n!^(mod-2)
        invFac[n]=modExp(fac[n],mod-2);
        for(int i=n-1;i>=0;i--)
            invFac[i]=(invFac[i+1]*(i+1))%mod;
    }

    inline ll nCr(ll n,ll r)
    {
        return ((fac[n]*invFac[r])%mod * invFac[n-r])%mod;
    }

    ll solve(vector<int>& arr)
    {
        if(!arr.size())
            return 1;

        int root=arr.front();
        vector<int>left;
        vector<int>right;

        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>root)
                right.push_back(arr[i]);
            else
                left.push_back(arr[i]);
        }
        
        ll ans=1;
        {
            ll to=right.size();
            ll sp=left.size()+1;
            ans=(ans*solve(left))%mod;
            ans=(ans*solve(right))%mod;
            ans=(ans*nCr(to+sp-1,sp-1))%mod;
        }
        return ans;
    }

    int numOfWays(vector<int>& arr) {
        int n=arr.size();
        init(n+1);
        return solve(arr)-1;
    }
};