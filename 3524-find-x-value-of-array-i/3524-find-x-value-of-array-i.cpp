using ll=long long;
ll dp[100005][2][5][5];
class Solution {
public:

    ll solve(int x,bool start,int rem,vector<int>& arr,int k,int r)
    {
        if(x==arr.size())
            return (start && rem==r);
        if(dp[x][start][rem][r]!=-1)
            return dp[x][start][rem][r];
        ll ans=0;
        if(start)
        {
            // end here
            ans+=(rem==r);
            // continue
            ans+=solve(x+1,start,(1LL*rem*arr[x])%k,arr,k,r);
        }
        else
        {
            // no start
            ans+=solve(x+1,0,rem,arr,k,r);
            // start
            ans+=solve(x+1,1,arr[x]%k,arr,k,r);
        }
        return dp[x][start][rem][r]=ans;
    }

    vector<long long> resultArray(vector<int>& arr, int k) {
        vector<ll>ans(k);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<k;i++)
            ans[i]=solve(0,0,0,arr,k,i);
        return ans;
    }
};