int dp[100005];
class Solution {
public:

    int solve(int tar)
    {
        if(!tar)
            return dp[tar]=-1;
        if(dp[tar]!=-1)
            return dp[tar];
        int ans=2e9;
        int i=1;
        while(i*(i+1)<=2*tar)   
        {
            ans=min(ans,i+1+solve(tar-i*(i+1)/2));
            i++;
        }
        return dp[tar]=ans;
    }

    int minDays(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};