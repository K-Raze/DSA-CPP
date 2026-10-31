class Solution
{
public:
    const int mod = 1e9 + 7;

    bool isValid(int x, int y, int r, int c)
    {
        return x < r && y < c;
    }

    int dfs(int x, int y, int dir, vector<vector<int>> &mat,
            vector<vector<vector<int>>> &dp)
    {
        int r = mat.size(), c = mat[0].size();
        if (!isValid(x, y, r, c))
            return 0;
        if (x == r - 1 && y == c - 1)
            return 1;
        if (dp[x][y][dir] != -1)
            return dp[x][y][dir];

        if (mat[x][y])
        {
            if (dir == 0)
                return dp[x][y][dir] = dfs(x + 1, y, 1, mat, dp)%mod;
            else
                return dp[x][y][dir] = dfs(x, y + 1, 0, mat, dp)%mod;
        }

        int ways=dfs(x+1,y,1,mat,dp)%mod;
        ways+=dfs(x,y+1,0,mat,dp)%mod;
        
        return dp[x][y][dir] = ways % mod;
    }

    int uniquePaths(vector<vector<int>> &mat)
    {
        int r = mat.size(), c = mat[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(2, -1)));
        return dfs(0, 0, 0, mat, dp);
    }
};