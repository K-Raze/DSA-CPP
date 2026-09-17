using ll=long long;
const ll mod=1e9+7;
class Solution {
public:

    vector<ll>fac,invFac;

    ll modExp(ll b,ll p)
    {
        if(!p)
            return 1;
        ll temp=modExp(b,p/2);
        temp=(temp*temp)%mod;
        if(p&1)
            temp=(temp*b)%mod;
        return temp;
    }

    void init(ll n)
    {
        fac.resize(n+1);
        invFac.resize(n+1);
        fac[0]=1;
        invFac[0]=1;
        for(int i=1;i<=n;i++)
            fac[i]=(fac[i-1]*i)%mod;
        invFac[n]=modExp(fac[n],mod-2);
        for(int i=n-1;i>=1;i--)
            invFac[i]=((i+1)*invFac[i+1])%mod;
    }

    vector<string>parse(string& s)
    {
        vector<string>ans;
        string temp;
        for(char& ch : s)
        {
            if(ch!=' ')
                temp+=ch;
            else
            {
                ans.push_back(temp);
                temp.clear();
            }
        }
        ans.push_back(temp);
        return ans;
    }

    int countAnagrams(string s) {
        init((ll)s.size());
        vector<string>words=parse(s);
        ll ans=1;
        for(string& str : words)
        {
            ans=(ans*fac[str.size()])%mod;
            vector<ll>cnt(26,0);
            for(char& ch : str)
                cnt[ch-'a']++;
            for(int i=0;i<26;i++)
                ans=(ans*invFac[cnt[i]])%mod;
        }
        return ans;
    }
};