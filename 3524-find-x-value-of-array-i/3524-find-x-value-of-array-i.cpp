using ll=long long;
ll dp[100005][5];
class Solution {
public:

    ll solve(int x,int rem,vector<int>& arr,int k,int r)
    {
        if(x==arr.size())
            return (rem==r);
        if(dp[x][rem]!=-1)
            return dp[x][rem];
        ll ans=0;
        {
            // end here
            ans+=(rem==r);
            // continue
            ans+=solve(x+1,(1LL*rem*arr[x])%k,arr,k,r);
        }
        return dp[x][rem]=ans;
    }

    vector<long long> resultArray(vector<int>& arr, int k) {
        vector<ll>ans(k);
        for(int i=0;i<k;i++)
        {
            memset(dp,-1,sizeof(dp));
            ll val=0;
            for(int j=0;j<arr.size();j++)
                val+=solve(j+1,arr[j]%k,arr,k,i);
            ans[i]=val;
        }
        return ans;
    }
};