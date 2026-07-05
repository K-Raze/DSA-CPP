const int mod=1e9+7;
const int ninf=-2e9;
using pii=pair<int,int>;

pii dp[101][101];

class Solution {
public:

    pii solve(int x,int y,vector<string>& mat)
    {
        if(!x && !y)
            return {0,1};

        if(dp[x][y].first!=-1)
            return dp[x][y];

        pii left={ninf,0};
        pii up={ninf,0};
        pii dig={ninf,0};

        // left
        if(y-1>=0 && mat[x][y-1]!='X')
            left=solve(x,y-1,mat);
        // up
        if(x-1>=0 && mat[x-1][y]!='X')
            up=solve(x-1,y,mat);
        // dig
        if(x-1>=0 && y-1>=0 && mat[x-1][y-1]!='X')
            dig=solve(x-1,y-1,mat);

        int maxSum=max(up.first,max(dig.first,left.first));

        if(maxSum==ninf)
            return dp[x][y]={ninf,0};
        
        pii ans={mat[x][y]-'0'+maxSum,0};

        if(left.first==maxSum)
            ans.second=(ans.second+left.second)%mod;
        if(up.first==maxSum)
            ans.second=(ans.second+up.second)%mod;
        if(dig.first==maxSum)
            ans.second=(ans.second+dig.second)%mod;
        return dp[x][y]=ans;
    }

    vector<int> pathsWithMaxScore(vector<string>& mat) {
        mat[0][0]='0';
        mat[mat.size()-1][mat[0].size()-1]='0';
        memset(dp,-1,sizeof(dp));
        pii ans=solve(mat.size()-1,mat[0].size()-1,mat);
        if(ans.first==ninf)
            return {0,0};
        return {ans.first,ans.second};
    }
};