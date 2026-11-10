using ll=long long;
ll dp[100005];
class Solution {
public:

    ll solve(int x,int n, vector<int>& costs)
    {
        if(x==n)
            return 0;
        if(dp[x]!=-1)
            return dp[x];
        // i+1
        ll ans=LLONG_MAX;
        if(x+1<=n)
            ans=min(ans,1+costs[x]+solve(x+1,n,costs));
        if(x+2<=n)
            ans=min(ans,4+costs[x+1]+solve(x+2,n,costs));
        if(x+3<=n)
            ans=min(ans,9+costs[x+2]+solve(x+3,n,costs));
        return dp[x]=ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,costs);
    }
};