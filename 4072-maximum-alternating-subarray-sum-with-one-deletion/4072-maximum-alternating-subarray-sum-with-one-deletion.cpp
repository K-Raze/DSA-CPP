using ll=long long;
bool vis[100005][2][2][2];
ll dp[100005][2][2][2];
class Solution {
public:

    ll solve(int x,bool par,bool skip,bool start,vector<int>& arr)
    {
        if(x==arr.size())
            return 0;

        if(vis[x][par][skip][start])
            return dp[x][par][skip][start];
        vis[x][par][skip][start]=1;
        // end here
        ll ans=0;
        if(start)
            ans=arr[x];
        // skip this one
        if(!skip && !start)
            ans=max(ans,solve(x+1,par,1,0,arr));
        // take
        ll adder=(par) ? -arr[x] : arr[x];
        ans=max(ans,adder+solve(x+1,1-par,skip,0,arr));
        return dp[x][par][skip][start]= ans;
    }

    long long maxAlternatingSum(vector<int>& arr) {
        ll ans=-4e18;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<arr.size();i++)
            ans=max(ans,solve(i,0,0,1,arr));
        return ans;
    }
};