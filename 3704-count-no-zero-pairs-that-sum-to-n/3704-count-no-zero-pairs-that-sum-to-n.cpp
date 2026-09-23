using ll=long long;
ll dp[16][2][2][2];
class Solution {
public:

    ll solve(int x,bool carry,bool au,bool ad,string& s)
    {
        if(x==s.size())
            return !au && !ad && !carry;
        
        if(dp[x][carry][au][ad]!=-1)
            return dp[x][carry][au][ad];

        ll ans=0;

        if(au && ad)
        {
            for(int a=1;a<=9;a++)
                for(int b=1;b<=9;b++)
                    if((a+b+carry)%10==s[x]-'0')
                    {
                        // au deac
                        ans+=solve(x+1,(a+b+carry)/10,0,1,s);
                        // ad deac
                        ans+=solve(x+1,(a+b+carry)/10,1,0,s);
                        // both ac
                        ans+=solve(x+1,(a+b+carry)/10,1,1,s);
                        // both dc
                        ans+=solve(x+1,(a+b+carry)/10,0,0,s);
                    }
        }
        else if(au)
        {
            for(int a=1;a<=9;a++)
                if((a+carry)%10==s[x]-'0')
                {
                    ans+=solve(x+1,(a+carry)/10,1,0,s);
                    ans+=solve(x+1,(a+carry)/10,0,0,s);
                }
        }
        else if(ad)
        {
            for(int a=1;a<=9;a++)
                if((a+carry)%10==s[x]-'0')
                {
                    ans+=solve(x+1,(a+carry)/10,0,1,s);
                    ans+=solve(x+1,(a+carry)/10,0,0,s);
                }
        }
        else
        {
            if(carry==s[x]-'0')
                ans+=solve(x+1, 0, 0, 0, s); 
        }
        return dp[x][carry][au][ad]=ans;
    }

    long long countNoZeroPairs(long long n) {
        string s=to_string(n);
        reverse(s.begin(),s.end());

        memset(dp,-1,sizeof(dp));
        return solve(0,0,1,1,s);
    }
};