using ll=long long;
ll dp[100005][2];
class Solution {
public:

    ll solve(int x,bool turn,vector<int>& arr)
    {
        if(x==arr.size())
            return 0;
        if(dp[x][turn]!=-1)
            return dp[x][turn];
        ll ans;
        if(!turn) // alice
        {
            // take 1
            {
                bool rem=arr[x]%3;
                bool nt=(!rem) ? 1-turn : turn;
                ans=arr[x]+solve(x+1,nt,arr);
            }
            // take 2
            if(x+1<arr.size())
            {
                bool rem=(arr[x]+arr[x+1])%3;
                bool nt=(!rem) ? 1-turn : turn;
                ans=max(ans,arr[x]+arr[x+1]+solve(x+2,nt,arr));
            }
        }
        else // bob
        {
            // take 1
            {
                bool rem=arr[x]%3;
                bool nt=(!rem) ? 1-turn : turn;
                ans=-arr[x]+solve(x+1,nt,arr);
            }
            // take 2
            if(x+1<arr.size())
            {
                bool rem=(arr[x]+arr[x+1])%3;
                bool nt=(!rem) ? 1-turn : turn;
                ans=min(ans,-arr[x]-arr[x+1]+solve(x+2,nt,arr));
            }
        }
        return dp[x][turn]=ans;
    }

    long long maxDifference(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,arr);
    }
};