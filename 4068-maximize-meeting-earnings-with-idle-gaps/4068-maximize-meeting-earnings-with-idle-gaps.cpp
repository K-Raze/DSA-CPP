

using ll = long long;
ll dp[2][100005];

class Solution {
public:
    ll solve(int x, bool start, vector<vector<int>>& arr) {
        if (dp[start][x] != -1)
            return dp[start][x];
            
        ll ans = arr[x][2];
        
        if (x + 1 < arr.size()) {
            ll adder = arr[x + 1][0] - arr[x][0];
            if (!start)
                adder = 0;
            ans = max(ans, adder + solve(x + 1, start, arr));
        }
        
        int low = x + 1;
        int high = arr.size() - 1;
        int nIdx = arr.size();
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid][0] >= arr[x][1]) {
                nIdx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (nIdx < arr.size()) {
            ans = max(ans, (ll)arr[x][2] + arr[nIdx][0] - arr[x][1] + solve(nIdx, 1, arr));
        }
        
        return dp[start][x] = ans;
    }

    long long maxEarnings(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            dp[0][i] = -1;
            dp[1][i] = -1;
        }
        
        return solve(0, 0, arr);
    }
};