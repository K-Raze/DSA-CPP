using ll=long long;
const int mod = 1e9 + 7;
class Solution {
public:
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    int dp[1001][1001];
    
    int solve(int x, int y, vector<vector<int>> &grid)
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        ll ans = 1;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (grid[nx][ny] > grid[x][y])
                ans = (ans + solve(nx, ny, grid)) % mod;
        }
        return dp[x][y] = ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        n = grid.size();
        m = grid[0].size();
        ll ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = (ans + solve(i, j, grid)) % mod;
        return ans;
    }
};