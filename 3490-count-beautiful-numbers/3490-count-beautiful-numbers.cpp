int dp[10][2][2][82][82];
class Solution {
public:

    // ( 9 * 2 * 2 * 81 *81 ) * 81

    int solve(int x,bool strict,bool lead0,int modVal,int sum,string& s,int total)
    {
        if(x==s.size())
        {
            if(lead0 || sum!=total)
                return 0;
            return !modVal;
        }

        if(dp[x][strict][lead0][modVal][sum]!=-1)
            return dp[x][strict][lead0][modVal][sum];

        int ans=0;

        int lim=(strict) ? s[x]-'0' : 9;

        for(int dig=0;dig<=lim;dig++)
        {
            bool ns=(strict && (dig==lim));
            if(dig==0)
            {
                if(lead0)
                    ans+=solve(x+1,ns,lead0,modVal,sum+dig,s,total);
                else
                    ans+=solve(x+1,ns,lead0,0,sum+dig,s,total);
            }
            else
            {
                int nmv= (modVal==81) ? dig%total : (modVal*dig)%total;
                ans+=solve(x+1,ns,0,nmv,sum+dig,s,total);
            }
        }
        return dp[x][strict][lead0][modVal][sum]=ans;
    }

    int digDp(int n)
    {
        string s=to_string(n);
        int ans=0;
        for(int sum=1;sum<=81;sum++)
        {
            memset(dp,-1,sizeof(dp));
            ans+=solve(0,1,1,81,0,s,sum);
        }
        return ans;
    }

    int beautifulNumbers(int l, int r) {
        return digDp(r)-digDp(l-1);
    }
};