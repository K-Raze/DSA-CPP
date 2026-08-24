using ll=long long;
ll dp[16][1<<16];
const ll inf=4e18;
class Solution {
public:

    ll solve(int x,int mask,vector<vector<int>>& arr,int start)
    {
        if(dp[x][mask]!=-1)
            return dp[x][mask];
        if(__builtin_popcount(mask)==1)
            return dp[x][mask]=max(abs(arr[x][1]-start),arr[x][0]);
        int pMask=(mask^(1<<x));
        ll ans=inf;
        for(int i=0;i<arr.size();i++)
            if((pMask>>i)&1)
            {
                ll pTime=solve(i,pMask,arr,start);
                ans=min(ans,max(abs(arr[i][1]-arr[x][1])+pTime,(ll)arr[x][0]));
            }
        return dp[x][mask]=ans;
    }

    long long elevatorRequests(int n, int start, vector<vector<int>>& arr) {
        int sz=arr.size();
        int mask=(1<<sz)-1;
        ll ans=inf;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<arr.size();i++)
            ans=min(ans,solve(i,mask,arr,start));
        return ans;
    }
};