using ll=long long;
const int mod=1e9+7;
int dp[84][800][84];
class Solution {
public:

    vector<ll> fac, invFac;

    ll power(ll a, ll b)
    {
        ll ans = 1;
        while(b)
        {
            if(b & 1)
                ans = (ans * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }

    void precompute(int n)
    {
        fac.assign(n + 1, 1);
        invFac.assign(n + 1, 1);

        for(int i = 1; i <= n; i++)
            fac[i] = (fac[i - 1] * i) % mod;

        invFac[n] = power(fac[n], mod - 2);

        for(int i = n - 1; i >= 0; i--)
            invFac[i] = (invFac[i + 1] * (i + 1)) % mod;
    }

    ll nCr(int n, int r)
    {
        if(r < 0 || r > n)
            return 0;

        return ((fac[n] * invFac[r]) % mod * invFac[n - r]) % mod;
    }

    vector<int>cnt;

    ll solve(int x,int sum,int tk,int req,int n)
    {
        if(x==10)
        {
            if(sum==req && tk==(n+1)/2)
                return ( fac[tk]*fac[n-tk] )%mod;
            return 0;
        }
        if(dp[x][sum][tk]!=-1)
            return dp[x][sum][tk];
        ll ans=0;
        for(ll i=0;i<=cnt[x];i++)
        {
            ans=(ans+ ((invFac[i]*invFac[cnt[x]-i])%mod * solve(x+1,1LL*sum+x*i,tk+i,req,n))%mod)%mod;
        }
        return dp[x][sum][tk]=ans;
    }

    int countBalancedPermutations(string s) {
        int sum=0;
        for(char& ch : s)
            sum+=ch-'0';
        if(sum&1)
            return 0; 

        cnt.assign(10,0);
        for(char& ch : s)
            cnt[ch-'0']++;
        precompute(s.size()+5);
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,sum/2,s.size());
    }
};