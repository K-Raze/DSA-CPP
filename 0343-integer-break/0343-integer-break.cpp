using ll=long long;
class Solution {
public:

    ll modExp(ll b,ll p)
    {
        if(!p)
            return 1;
        ll ans=modExp(b,p/2);
        ans=(ans*ans);
        if(p&1)
            ans=(ans*b);
        return ans;
    }


    int integerBreak(int pf) {
        if(pf<4)
            return pf-1;

        ll cnt=pf/3;
        ll ans=modExp(3,cnt);

        if(pf%3==1)
            ans=(modExp(3,cnt-1)*4);
        else if(pf%3==2)
            ans=(ans*2);

        return ans;
    }
};