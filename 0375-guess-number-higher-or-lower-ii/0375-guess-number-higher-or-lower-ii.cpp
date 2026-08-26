int dp[205][205];
class Solution {
public:

    int solve(int l,int r)
    {
        if(l==r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int ans=INT_MAX;
        for(int g=l;g<=r;g++)
        {
            int temp=0;
            if(g-1>=l)
                temp=max(temp,g+solve(l,g-1));
            if(g+1<=r)
                temp=max(temp,g+solve(g+1,r));
            ans=min(ans,temp);
        }
        return dp[l][r]=ans;
    }    

    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
};