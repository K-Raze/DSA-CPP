using ll=long long;
const int MOD=1e9+7;

class Solution {
public:

    ll power(ll a,ll b)
    {
        ll ans=1;
        a%=MOD;
        while(b)
        {
            if(b&1)
                ans=ans*a%MOD;
            a=a*a%MOD;
            b>>=1;
        }
        return ans;
    }

    inline ll inv(ll x)
    {
        return power(x,MOD-2);
    }

    ll nCr(int n,int r,vector<ll>& fact)
    {
        if(r<0 || r>n)
            return 0;
        return fact[n]*inv(fact[r]*fact[n-r]%MOD)%MOD;
    }

    int countValidSequences(int n,int k) {
        vector<ll> fact(n+1);
        fact[0]=1;

        for(int i=1;i<=n;i++)
            fact[i]=fact[i-1]*i%MOD;

        ll total=nCr(n-1,k-1,fact);
        ll bad=0;

        if((n-k)%2==0)
        {
            int s=(n-k)/2;
            bad=nCr(s+k-1,k-1,fact);
        }

        return (total-bad+MOD)%MOD;
    }
};