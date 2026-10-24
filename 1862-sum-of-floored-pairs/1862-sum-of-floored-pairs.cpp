const int mod=1e9+7;
using ll=long long;
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& arr) {
        ll mx=*max_element(arr.begin(),arr.end());

        vector<ll>cnt(mx+5,0);
        for(int& x : arr)
            cnt[x]++;
        vector<ll>pre=cnt;
        for(int i=1;i<=mx;i++)
            pre[i]+=pre[i-1];
        
        unordered_set<int>st(arr.begin(),arr.end());

        ll ans=0;

        for(int val : st)
        {
            ll fin=0;
            for(int i=val*2;i<=mx+val;i+=val)
            {
                int l=i-val,r=min(mx,i-1LL);
                ll freq=pre[r]-pre[l-1];
                freq%=mod;
                fin=(fin+freq*(l/val))%mod;
            }
            fin=(fin*cnt[val])%mod;
            ans=(ans+fin)%mod;
        }
        return ans;
    }
};