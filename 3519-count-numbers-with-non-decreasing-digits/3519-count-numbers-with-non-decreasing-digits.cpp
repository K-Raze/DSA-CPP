class Solution {
public:

    const int MOD=1e9+7;
    int dp[335][2][10];

    int solve(int x,bool strict,int last,string& s,int b)
    {
        if(x==s.size())
            return 1;

        if(dp[x][strict][last]!=-1)
            return dp[x][strict][last];

        int lim=(strict) ? s[x]-'0' : b-1;
        int ans=0;
        for(int dig=last;dig<=lim;dig++)
        {
            bool newStrict=(strict && dig==lim);
            ans=(ans+solve(x+1,newStrict,dig,s,b))%MOD;
        }
        return dp[x][strict][last]=ans;
    }

    inline void trim(string& s)
    {
        reverse(s.begin(),s.end());
        while(!s.empty() && s.back()=='0')
            s.pop_back();
        reverse(s.begin(),s.end());
    }

    string convert(string& s,int b)
    {
        string ans;
        while(s.size())
        {
            int rem=0;
            string q;
            for(char& ch : s)
            {
                rem=(rem*10)+ch-'0';
                q+=(rem/b)+'0';
                rem%=b;
            }
            ans+=rem+'0';
            trim(q);
            s=q;
        }
        reverse(ans.begin(),ans.end());
        trim(ans);
        return ans;
    }

    int countNumbers(string l, string r, int b) {
        int ans=0;
        {
            string s=convert(r,b);
            memset(dp,-1,sizeof(dp));
            ans=solve(0,1,0,s,b);
        }
        {
            string s=convert(l,b);
            bool good=1;
            for(int i=1;i<s.size();i++)
                if(s[i-1]>s[i])
                    good=0;

            memset(dp,-1,sizeof(dp));
            ans=(ans-solve(0,1,0,s,b)+MOD)%MOD;

            if(good)
                ans=(ans+1)%MOD;
        }
        return ans;
    }
};
