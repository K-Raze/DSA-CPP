using ll = long long;
class Solution {
public:

    int n;
    const ll NEG = -1e15;
    vector<vector<ll>> dp;
    vector<vector<int>> adj;
    vector<int> mks;
    vector<ll> val;

    void dfs(int x)
    {
        // don't take this
        dp[x][0] = 0;
        // take this only
        if (mks[x] != -1)
            dp[x][mks[x]] = val[x];

        for (int &y : adj[x])
        {
            dfs(y);
            vector<ll> ndp = dp[x];
            for (int m1 = 0; m1 < (1 << 10); m1++)
            {
                if (dp[x][m1] == NEG)
                    continue;
                for (int m2 = 0; m2 < (1 << 10); m2++)
                {
                    if (dp[y][m2] == NEG)
                        continue;
                    if ((m1 & m2) == 0)
                        ndp[m1 | m2] = max(ndp[m1 | m2], dp[x][m1] + dp[y][m2]);
                }
            }
            dp[x] = ndp;
        }
    }

    int goodSubtreeSum(vector<int>& vals, vector<int>& par)
    {
        n = vals.size();
        val.assign(vals.begin(), vals.end());
        adj.assign(n, {});
        for (int i = 1; i < n; i++)
            adj[par[i]].push_back(i);

        dp.assign(n, vector<ll>(1 << 10, NEG));
        mks.resize(n);

        for (int i = 0; i < n; i++)
        {
            int mask = 0;
            bool ok = 1;
            string s = to_string(vals[i]);
            for (char &ch : s)
            {
                int bit = ch - '0';
                if ((mask >> bit) & 1)
                {
                    ok = 0;
                    break;
                }
                mask |= (1 << bit);
            }
            mks[i] = (ok ? mask : -1);
        }

        dfs(0);
        const ll mod = 1e9 + 7;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll best = 0;
            for (int m = 0; m < (1 << 10); m++)
                best = max(best, dp[i][m]);
            ans = (ans + best) % mod;
        }
        return ans;
    }
};