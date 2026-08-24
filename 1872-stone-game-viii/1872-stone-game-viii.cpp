class Solution {
public:

    const int inf=2e9;

    // a b c d e //.    +(a+b)
    // (a+b) c d e //.    -(a+b+c)
    // (a+b+c) d e //.    +(a+b+c+d+e)
    // (a+b+c+d+e) //.    

    int dp[100005][2];

    int solve(int x,bool turn,vector<int>& pre)
    {
        if(x==pre.size()-1)
        {
            if(turn)
                return pre[x];
            return -pre[x];
        }

        if(dp[x][turn]!=-1)
            return dp[x][turn];

        int ans;
        if(turn)
        {
            ans=pre[x]+solve(x+1,1-turn,pre);
            ans=max(ans,solve(x+1,turn,pre));
        }
        else
        {
            ans=-pre[x]+solve(x+1,1-turn,pre);
            ans=min(ans,solve(x+1,turn,pre));
        }
        return dp[x][turn]=ans;
    }

    int stoneGameVIII(vector<int>& arr) {
        for(int i=1;i<arr.size();i++)
            arr[i]+=arr[i-1];
        memset(dp,-1,sizeof(dp));
        return solve(1,1,arr);
    }
};