class Solution {
public:

    int dp[255][255];

    int solve(int b,int a,vector<vector<int>>& mat, int limit)
    {
        if(b==mat[0].size())
            return 0;

        if(dp[b][a]!=-1)
            return dp[b][a];

        int ans=solve(b+1,a,mat,limit);

        if(a==mat[0].size())
            ans=max(ans,1+solve(b+1,b,mat,limit));
        else
        {
            bool canTake=1;
            for(int r=0;r<mat.size();r++)
                if(abs(mat[r][b]-mat[r][a])>limit)
                    canTake=0;
            if(canTake)
                ans=max(ans,1+solve(b+1,b,mat,limit));
        }
        return dp[b][a]=ans;
    }

    int maxConsistentColumns(vector<vector<int>>& mat, int limit) {
        memset(dp,-1,sizeof(dp));
        return solve(0,mat[0].size(),mat,limit);
    }
};