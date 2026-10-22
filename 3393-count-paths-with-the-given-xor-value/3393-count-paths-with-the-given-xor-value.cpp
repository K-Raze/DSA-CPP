const int mod=1e9+7;
class Solution {
public:

    int dp[300][300][16];

    int solve(int i,int j,int xr,vector<vector<int>>& grid,int k)
    {
        int m=grid.size();
        int n=grid[0].size();

        xr^=grid[i][j];

        if(i==m-1 && j==n-1)
            return xr==k;

        int &ans=dp[i][j][xr];

        if(ans!=-1)
            return ans;

        ans=0;

        if(i+1<m)
            ans=(ans+solve(i+1,j,xr,grid,k))%mod;

        if(j+1<n)
            ans=(ans+solve(i,j+1,xr,grid,k))%mod;

        return ans;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid,int k)
    {
        memset(dp,-1,sizeof(dp));

        return solve(0,0,0,grid,k);
    }
};