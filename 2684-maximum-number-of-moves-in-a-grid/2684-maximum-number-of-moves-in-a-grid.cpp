int dp[1001][1001];
class Solution {
public:

    int r[3]={-1,0,1};
    int c[3]={1,1,1};

    int n,m;
    bool isValid(int x,int y)
    {
        return x>=0 && x<n && y>=0 && y<m;
    }

    int solve(int x,int y,vector<vector<int>>& mat)
    {
        if(dp[x][y]!=-1)
            return dp[x][y];
        int ans=0;
        for(int k=0;k<3;k++)
        {
            int nx=x+r[k];
            int ny=y+c[k];
            if(isValid(nx,ny) && mat[nx][ny]>mat[x][y])
                ans=max(ans,1+solve(nx,ny,mat));
        }
        return dp[x][y]=ans;
    }

    int maxMoves(vector<vector<int>>& mat) {
        n=mat.size(),m=mat[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++)
                ans=max(ans,solve(i,0,mat));
        return ans;
    }
};