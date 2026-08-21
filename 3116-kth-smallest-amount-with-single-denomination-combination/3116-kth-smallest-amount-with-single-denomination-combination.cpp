using ll=long long;
class Solution {
public:

    ll gcdll(ll a,ll b)
    {
        if(!b)
            return a;
        return gcdll(b,a%b);
    }

    ll lcmll(ll a,ll b)
    {
        return 1LL*(a/gcdll(a,b))*b;
    }

    ll findPosi(ll n,vector<int>& arr)
    {
        ll posi=0;
        for(ll mask=1;mask<(1LL<<arr.size());mask++)
        {
            ll lcm=1;
            for(int i=0;i<arr.size();i++)
                if((mask>>i)&1)
                    lcm=lcmll(lcm,arr[i]);
            if(__builtin_popcount(mask)&1)
                posi+=n/lcm;
            else
                posi-=n/lcm;
        }
        return posi;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll start=1, end=5e10;
        while(start<=end)
        {
            ll mid=start+((end-start)>>1);
            if(findPosi(mid,coins)>=k)
                end=mid-1;
            else
                start=mid+1;
        }
        return start;
    }
};