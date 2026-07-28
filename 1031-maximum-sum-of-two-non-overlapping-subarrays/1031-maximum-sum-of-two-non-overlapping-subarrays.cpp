class Solution {
public:

    const int ninf=-2e9;
    int dp[1005][2][2];

    int solve(int x,bool f,bool s,vector<int>& pre,int l1,int l2)
    {
        if(f && s)
            return 0;
        if(x>=pre.size())
            return ninf;

        if(dp[x][f][s]!=-1)
            return dp[x][f][s];

        // skip
        int ans=solve(x+1,f,s,pre,l1,l2);

        // l1 lele
        if(!f)
        {
            if(x+l1-1<pre.size())
            {
                ans=max(ans,
                        pre[x+l1-1]-((x-1>=0) ? pre[x-1] : 0)
                        +solve(x+l1,1,s,pre,l1,l2));
            }
        }

        // l2 lele
        if(!s)
        {
            if(x+l2-1<pre.size())
            {
                ans=max(ans,
                        pre[x+l2-1]-((x-1>=0) ? pre[x-1] : 0)
                        +solve(x+l2,f,1,pre,l1,l2));
            }
        }

        return dp[x][f][s]=ans;
    }

    int maxSumTwoNoOverlap(vector<int>& arr, int firstLen, int secondLen) {
        for(int i=1;i<arr.size();i++)
            arr[i]+=arr[i-1];

        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,arr,firstLen,secondLen);
    }
};