class Solution
{
    public:

        vector<vector < int>> dp;

    int way(int x, int y, string &s, string &t)
    {
        if (y == 0)
            return 1;
        if (x == 0)
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];

        if (s[x - 1] == t[y - 1])
            return dp[x][y] = way(x - 1, y - 1, s, t) + way(x - 1, y, s, t);
        else
            return dp[x][y] = way(x - 1, y, s, t);
    }

    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        dp = vector<vector < int>> (n + 1, vector<int> (m + 1, -1));
        return way(n, m, s, t);
    }
};