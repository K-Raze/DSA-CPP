// min of max
int dp[102][10002];
class Solution {
public:

    int solve(int n,int k)
    {
        if(k==1)
            return n;
        if(n==1)
            return 1;
        if(n<=0)
            return 0;

        if(dp[k][n]!=-1)
            return dp[k][n];

        int ans=2e9;

        // for(int f=1;f<=n;f++)
        //     ans=min(ans,1+max(solve(f-1,k-1),solve(n-f,k)));

        int low=1,high=n;
        while(low<=high)
        {
            int f=low+((high-low)>>1);
            int eggBreak=solve(f-1,k-1);
            int eggNotBreak=solve(n-f,k);
            
            ans=min(ans,1+max(eggBreak,eggNotBreak));

            if(eggNotBreak>=eggBreak)
                low=f+1;
            else
                high=f-1;
        }

        return dp[k][n]=ans;
    }

    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};