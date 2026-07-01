class Solution {
public:

    int dp[1<<14];

    int solve(int mask,vector<int>& arr1, vector<int>& arr2)
    {
        int bp=__builtin_popcount(mask);
        if(bp==arr1.size())
            return 0;
        if(dp[mask]!=-1)
            return dp[mask];
        int ans=2e9;
        for(int i=0;i<arr2.size();i++)
            if(!((mask>>i)&1))
                ans=min(ans,(arr1[bp]^arr2[i])+
                    solve((mask | (1<<i)),arr1,arr2));
        return dp[mask]=ans;
    }

    int minimumXORSum(vector<int>& arr1, vector<int>& arr2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,arr1,arr2);
    }
};