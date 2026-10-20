int dp[33][1<<10];
const int mod=1e9+7;
class Solution {
public:

    vector<int>cnt;
    vector<vector<int>>primeFac;
    unordered_map<int,int>primeIdx;

    int modExp(int b,int p)
    {
        if(!p)
            return 1;
        int ans=modExp(b,p/2);
        ans=(1LL*ans*ans)%mod;
        if(p&1)
            ans=(1LL*b*ans)%mod;
        return ans;
    }

    int solve(int x,int mask)
    {
        if(x==31)
            return (mask) ? 1 : 0;
        if(dp[x][mask]!=-1)
            return dp[x][mask];
        // skip
        int ans=solve(x+1,mask);
        // take 
        // can i take it ?
        bool take=1;
        int nMask=mask;
        for(int& fac : primeFac[x])
        {
            int bit=primeIdx[fac];
            if((nMask>>bit)&1)
            {
                take=0;
                break;
            }
            else 
                nMask^=(1<<bit);
        }
        if(take)
            ans=(ans+1LL*cnt[x]*solve(x+1,nMask))%mod;
        return dp[x][mask]=ans;
    }

    int numberOfGoodSubsets(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        primeIdx.clear();
        {
            vector<int>temp={2,3,5,7,11,13,17,19,23,29};
            for(int i=0;i<10;i++)
                primeIdx[temp[i]]=i;
        }
        primeFac.assign(31,{});
        {
            for(int val=2;val<=30;val++)
            {
                int v=val;
                for(int i=2;i*i<=v;i++)
                    while(v%i==0)
                    {
                        primeFac[val].push_back(i);
                        v/=i;
                    }
                if(v>1)
                    primeFac[val].push_back(v);
            }
        }
        cnt.assign(31,0);
        for(int& x : arr)
            cnt[x]++;
        return (1LL*modExp(2,cnt[1])*solve(2,0))%mod;
    }
};