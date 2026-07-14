const int mod=1e9+7;
int dp[202][202][202];
class Solution {
public:

    int gcd(int a,int b)
    {
        while(b)
        {
            a%=b;
            swap(a,b);
        }
        return a;
    }

    int solve(int x,int g1,int g2,vector<int>& arr)
    {
        if(x==arr.size())
            return (g1==g2);

        if(dp[x][g1][g2]!=-1)
            return dp[x][g1][g2];

        // skip
        int ans=solve(x+1,g1,g2,arr);
        // take
            // 1st
        ans=(ans+solve(x+1,gcd(g1,arr[x]),g2,arr))%mod;
            // 2nd
        ans=(ans+solve(x+1,g1,gcd(g2,arr[x]),arr))%mod;
        return dp[x][g1][g2]=ans;
    }

    int subsequencePairCount(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,arr)-1;
    }
};