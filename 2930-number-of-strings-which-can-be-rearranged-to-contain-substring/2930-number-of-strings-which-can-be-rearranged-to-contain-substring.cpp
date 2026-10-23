using ll=long long;
const int mod=1e9+7;
int dp[100005][2][2][3];
class Solution {
public:

    ll solve(int x,bool isL,bool isT,int cntE,int n)
    {
        if(x==n)
            return (isL && isT && (cntE==2));
        if(dp[x][isL][isT][cntE]!=-1)
            return dp[x][isL][isT][cntE];
        ll ans=0;
        for(char ch='a';ch<='z';ch++)
        {
            bool nisL=isL;
            bool nisT=isT;
            int ncntE=cntE;
            if(ch=='l')
                nisL=1;
            else if(ch=='t')
                nisT=1;
            if(ch=='e')
                ncntE=min(2,ncntE+1);
            ans=(ans+solve(x+1,nisL,nisT,ncntE,n))%mod;
        }
        return dp[x][isL][isT][cntE]=ans;
    }

    int stringCount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,0,n);
    }
};