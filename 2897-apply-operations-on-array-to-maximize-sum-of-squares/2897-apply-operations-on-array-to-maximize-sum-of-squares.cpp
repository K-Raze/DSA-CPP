const int mod=1e9+7;
class Solution {
public:
    int maxSum(vector<int>& arr, int k) {
        vector<int>cnt(32,0);
        for(int& x : arr)
            for(int bit=31;bit>=0;bit--)
                if((x>>bit)&1)
                    cnt[bit]++;
        int ans=0;
        while(k--)
        {
            int val=0;
            for(int bit=31;bit>=0;bit--)
                if(cnt[bit])
                {
                    cnt[bit]--;
                    val+=(1<<bit);
                }
            ans=(ans+1LL*val*val)%mod;
        }
        return ans;
    }
};