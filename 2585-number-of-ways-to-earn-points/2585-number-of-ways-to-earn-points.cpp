const int mod=1e9+7;
int dp[52][1002];
class Solution {
public:

    int solve(int x,int tar,vector<vector<int>>& types)
    {
        if(!tar)
            return 1;
        if(x==types.size())
            return 0;
        
        if(dp[x][tar]!=-1)
            return dp[x][tar];

        int ans=0;
        for(int take=0;take<=types[x][0];take++)
        {
            if(tar-1LL*take*types[x][1]>=0)
                ans=(ans+solve(x+1,tar-1LL*take*types[x][1],types))%mod;
            else
                break;
        }
        return dp[x][tar]=ans;
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memset(dp,-1,sizeof(dp));
        return solve(0,target,types);
    }
};