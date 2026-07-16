using ll=long long;
class Solution {
public:

    ll gcdll(ll a, ll b)
    {
        while(b){ a %= b; swap(a, b); }
        return a;
    }
    
    long long gcdSum(vector<int>& arr) {
        int n=arr.size();
        vector<ll>preGcd(n);
        ll maxi=-1;
        ll g=0;
        for(int i=0;i<n;i++)
            {
                maxi=max((ll)arr[i],maxi);
                g=gcdll(arr[i],maxi);
                preGcd[i]=g;
            }
        sort(preGcd.begin(),preGcd.end());
        int l=0,r=n-1;
        ll ans=0;
        while(l<r)
            {
                ans+=gcdll(preGcd[l],preGcd[r]);
                l++;
                r--;
            }
        return ans;
    }
};