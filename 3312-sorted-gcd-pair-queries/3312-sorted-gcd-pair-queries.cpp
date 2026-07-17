using ll=long long;
class Solution {
public:

    // 4  8 12 16 20

    vector<int> gcdValues(vector<int>& arr, vector<long long>& queries) {

        int maxEle=*max_element(arr.begin(),arr.end());
        vector<int>cnt(maxEle+1,0);
        for(int& x : arr)
            for(int i=1;i*i<=x;i++)
                if(x%i==0)
                {
                    cnt[i]++;
                    if(x/i!=i)
                        cnt[x/i]++;
                }

        vector<ll>gPair(maxEle+1,0);

        for(int val=maxEle;val>=1;val--)
        {
            gPair[val]=1LL*cnt[val]*(cnt[val]-1)/2;
            for(int j=val+val;j<=maxEle;j+=val)
                gPair[val]-=gPair[j];
        }
        for(int i=2;i<=maxEle;i++)
            gPair[i]+=gPair[i-1];
        vector<int>ans;
        for(ll& q : queries)
            ans.push_back(lower_bound(gPair.begin()+1,gPair.end(),q+1)
                -gPair.begin());
        return ans;
    }
};