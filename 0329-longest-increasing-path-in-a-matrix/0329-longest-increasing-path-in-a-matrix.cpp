class Solution {
public:

    int r[4]={0,0,-1,1};
    int c[4]={-1,1,0,0};

    bool isValid(int x,int y,int row,int col){
        return x>=0 && y>=0 && x<row && y<col;
    }

    int way(int x,int y,vector<vector<int>>& mat,vector<vector<int>>& dp)
    {
        if(dp[x][y])
            return dp[x][y];
        int temp=1;
        for(int k=0;k<4;k++)
            if(isValid(x+r[k],y+c[k],mat.size(),mat[0].size()) && mat[x+r[k]][y+c[k]]>mat[x][y])
                temp=max(temp,1+way(x+r[k],y+c[k],mat,dp));
        return dp[x][y]=temp;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=1;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans=max(ans,way(i,j,matrix,dp));
        return ans;
    }
};