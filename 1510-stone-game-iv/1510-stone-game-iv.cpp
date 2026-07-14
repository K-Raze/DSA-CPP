class Solution {
public:
    
    int dp[100001];
    
    bool solve(int n)
    {
        if (!n)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        bool ans = 0;
        for (int i = 1; i * i <= n; i++)
            if (!solve(n - i * i))
            {
                ans = 1;
                break;
            }
        return dp[n] = ans;
    }

    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};