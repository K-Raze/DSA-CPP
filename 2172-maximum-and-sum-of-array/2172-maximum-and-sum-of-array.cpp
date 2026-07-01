class Solution {
public:

    int dp[18][1<<9+1][1<<9+1];

    int solve(int x,int m1,int m2,vector<int>& arr, int ns)
    {
        if(x==arr.size())
            return 0;
        if(dp[x][m1][m2]!=-1)
            return dp[x][m1][m2];
        int ans=0;
        for(int i=1;i<=ns;i++)
        {
            if(!((m1>>i)&1))
                ans=max(ans,(i & arr[x])+solve(x+1,(m1 | (1<<i)),m2,arr,ns));
            else if(!((m2>>i)&1))
                ans=max(ans,(i & arr[x])+solve(x+1,m1,(m2 | (1<<i)),arr,ns));
        }
        return dp[x][m1][m2]=ans;
    }

    int maximumANDSum(vector<int>& arr, int ns) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,arr,ns);
    }
};