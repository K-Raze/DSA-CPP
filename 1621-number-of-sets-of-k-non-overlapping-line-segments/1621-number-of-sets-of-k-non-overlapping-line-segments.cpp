const int mod=1e9+7;
int dp[2][1005][1005];
class Solution {
public:

    int n;

    int solve(int x,int k,bool ext)
    {
        if(!k && !ext)
            return 1;
        if(x>=n)
            return 0;
        if(dp[ext][x][k]!=-1)
            return dp[ext][x][k];
        int ans=0;
        if(ext)
        {
            // extend krde
            ans=(ans+solve(x+1,k,1))%mod;
            // extend rokde
            ans=(ans+solve(x,k,0))%mod;
        }
        else
        {
            // skip this
            ans=(ans+solve(x+1,k,0))%mod;
            // take this
            if(x<n-1 && k)
                ans=(ans+solve(x+1,k-1,1))%mod;
        }
        return dp[ext][x][k]=ans;
    }

    int numberOfSets(int n, int k) {
        this->n=n;
        memset(dp,-1,sizeof(dp));
        return solve(0,k,0);
    }
};