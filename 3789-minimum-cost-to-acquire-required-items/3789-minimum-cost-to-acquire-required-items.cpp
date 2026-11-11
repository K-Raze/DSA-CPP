using ll=long long;

class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        ll ans=0;
        if(c1+c2>cb)
        {
            ll k=min(n1,n2);
            n1-=k;
            n2-=k;
            ans+=1LL*k*cb;
        }
        if(n1)
            ans+=1LL*n1*min(cb,c1);
        if(n2)
            ans+=1LL*n2*min(cb,c2);
        return ans;
    }
};