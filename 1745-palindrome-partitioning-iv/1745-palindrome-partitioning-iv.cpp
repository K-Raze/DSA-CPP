int dp[2005][2005];
int memo[2005][2005];
class Solution {
public:

    bool isPal(int l,int r,string& s)
    {
        if(l>=r)
            return 1;
        if(dp[l][r]!=-1)
            return dp[l][r];
        bool ans=0;
        if(s[l]==s[r])
            ans=isPal(l+1,r-1,s);
        return dp[l][r]=ans;
    }

    bool solve(int l,int r,int cnt,string& s)
    {
        if(r==s.size()-1)
        {
            if(isPal(l,r,s) && cnt==2)
                return 1;
            return 0;
        }
        if(memo[l][r]!=-1)
            return memo[l][r];
        // skip
        int ans=solve(l,r+1,cnt,s);
        // take
        if(isPal(l,r,s))
            ans|=solve(r+1,r+1,cnt+1,s);
        return memo[l][r]=ans;
    }

    bool checkPartitioning(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        memset(memo,-1,sizeof(memo));
        return solve(0,0,0,s);

    }
};