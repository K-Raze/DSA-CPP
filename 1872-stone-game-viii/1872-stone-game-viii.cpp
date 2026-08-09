class Solution {
public:

    const int inf=2e9;

    // a b c d e //.    +(a+b)
    // (a+b) c d e //.    -(a+b+c)
    // (a+b+c) d e //.    +(a+b+c+d+e)
    // (a+b+c+d+e) //.    

    // int solve(int x,int turn,vector<int>& pre)
    // {
    //     if(x==pre.size())
    //         return 0;
    //     int ans;
    //     if(turn) // alice max krega
    //     {
    //         ans=-inf;
    //         for(int i=max(1,x);i<pre.size();i++)
    //             ans=max(ans,pre[i]+solve(i+1,1-turn,pre));
    //     }
    //     else
    //     {
    //         ans=inf;
    //         for(int i=max(1,x);i<pre.size();i++)
    //             ans=min(ans,-pre[i]+solve(i+1,1-turn,pre));
    //     }
    //     return ans;
    // }

    int stoneGameVIII(vector<int>& arr) {
        int n=arr.size();
        vector<int>pre=arr;
        for(int i=1;i<n;i++)
            pre[i]+=pre[i-1];

        int dp[n+1][2];
        dp[n][0]=dp[n][1]=0;
        int predp[2][n+1];
        predp[0][n]=inf;
        predp[1][n]=-inf;
        for(int x=n-1;x>=0;x--)
            for(int turn=0;turn<=1;turn++)
            {   
                if(turn)
                {
                    predp[turn][x]=pre[x]+dp[x+1][1-turn];
                    predp[turn][x]=max(predp[turn][x],predp[turn][x+1]);
                }
                else
                {
                    predp[turn][x]=-pre[x]+dp[x+1][1-turn];
                    predp[turn][x]=min(predp[turn][x],predp[turn][x+1]);
                }
                int ans;
                if(turn) // alice max krega
                {
                    ans=-inf;
                    // for(int i=max(1,x);i<pre.size();i++)
                    //     ans=max(ans,pre[i]+dp[i+1][1-turn]);
                    ans=max(ans,predp[turn][max(1,x)]);
                }
                else
                {
                    ans=inf;
                    // for(int i=max(1,x);i<pre.size();i++)
                    //     ans=min(ans,-pre[i]+dp[i+1][1-turn]);
                    ans=min(ans,predp[turn][max(1,x)]);
                }
                dp[x][turn]=ans;
            }

        return dp[0][1];
    }
};