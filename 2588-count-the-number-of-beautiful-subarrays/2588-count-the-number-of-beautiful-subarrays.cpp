using ll=long long;
class Solution {
public:
    long long beautifulSubarrays(vector<int>& arr) {
        unordered_map<ll,ll>xorCnt;
        xorCnt[0]=1;
        ll ans=0;
        ll pre=0;
        for(int& x : arr)
        {
            pre^=x;
            ans+=xorCnt[pre];
            xorCnt[pre]++;
        }
        return ans;
    }
};