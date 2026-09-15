int dp[2005];
using ll=long long;
class Solution {
public:

    class RollingHash
    {
        public : 

        const ll m1 = 1000000007;
        const ll m2 = 1000000009;
        const ll b1 = 911382323;
        const ll b2 = 972663749;

        vector<ll>pre1,pre2,pow1,pow2;

        RollingHash(string& s)
        {
            int n=s.size();
            pre1.resize(n);
            pre2.resize(n);
            pow1.resize(n+1);
            pow2.resize(n+1);

            pow1[0]=1;
            for(int i=1;i<=n;i++)
                pow1[i]=(b1*pow1[i-1])%m1;
            pow2[0]=1;
            for(int i=1;i<=n;i++)
                pow2[i]=(b2*pow2[i-1])%m2;
            
            pre1[0]=s[0];
            pre2[0]=s[0];
            for(int i=1;i<n;i++)
            {
                pre1[i]=((pre1[i-1]*b1)%m1+s[i])%m1;
                pre2[i]=((pre2[i-1]*b2)%m2+s[i])%m2;
            }
        }

        pair<ll,ll>getHash(int l,int r)
        {
            ll ans1=pre1[r];
            if(l-1>=0)
                ans1=(ans1-(pre1[l-1]*pow1[r-l+1])%m1+m1)%m1;
            ll ans2=pre2[r];
            if(l-1>=0)
                ans2=(ans2-(pre2[l-1]*pow2[r-l+1])%m2+m2)%m2;
            return {ans1,ans2};
        }
    };

    int solve(int x,vector<int>& palIdx)
    {
        if(dp[x]!=-1)
            return dp[x];
        if(x==palIdx.size())
            return 0;
        int ans=solve(x+1,palIdx);
        if(palIdx[x]!=-1)
            ans=max(ans,1+solve(palIdx[x],palIdx));
        return dp[x]=ans;
    }


    int maxPalindromes(string s, int k) {
        int n=s.size();
        RollingHash rh1(s);
        reverse(s.begin(),s.end());
        RollingHash rh2(s);
        reverse(s.begin(),s.end());

        vector<int>palIdx(n,-1);
        for(int i=0;i<n;i++)
            for(int j=i+k-1;j<n;j++)
                if(rh1.getHash(i,j)==rh2.getHash(n-j-1,n-i-1))
                {
                    palIdx[i]=j+1;
                    break;
                }
        memset(dp,-1,sizeof(dp));
        return solve(0,palIdx);
    }
};