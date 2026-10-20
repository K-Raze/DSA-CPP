using ll=long long;
class Solution {
public:

    inline ll giveMask(ll n)
    {
        ll m=1;
        for(ll i=2;i*i<=n;i++)
        {
            ll cnt=0;
            while(n%i==0)
            {
                cnt++;
                n/=i;
            }
            if(cnt&1)
                m*=i;
        }
        if(n>1)
            m*=n;
        return m;
    }


    long long maximumSum(vector<int>& arr) {

        unordered_map<ll,ll>maskSum;
        for(int i=1;i<=arr.size();i++)
            maskSum[giveMask(i)]+=arr[i-1];
            
        ll ans=0;
        for(auto&[a,b] : maskSum)
            ans=max(ans,b);
        return ans;
    }
};