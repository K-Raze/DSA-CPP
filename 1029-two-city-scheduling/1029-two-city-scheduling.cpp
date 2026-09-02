class Solution {
public:

    int dp[52][102];

    int solve(int x,int k,vector<vector<int>>& arr)
    {
        if(x==arr.size())
            return 0;
        if(dp[k][x]!=-1)
            return dp[k][x];
        // 1st ko de
        int ans=INT_MAX;
        if(k<arr.size()/2)
            ans=min(ans,arr[x][0]+solve(x+1,k+1,arr));
        if(x-k<arr.size()/2)
            ans=min(ans,arr[x][1]+solve(x+1,k,arr));
        return dp[k][x]=ans;
    }

    int twoCitySchedCost(vector<vector<int>>& arr) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,arr);
    }
};