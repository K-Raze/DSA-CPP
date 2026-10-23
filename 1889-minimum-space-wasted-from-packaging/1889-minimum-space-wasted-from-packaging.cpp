using ll=long long;
const int mod=1e9+7;
class Solution {
public:
    // it = -1 agey
    // 2 3 5
    // 4 8
    // it=-1
    // it=1 agey
    // 2 -: 4*2-5
    //  

    inline ll waste(vector<int>& arr1,vector<int>& arr2,vector<ll>& pre)
    {
        ll ans=0;
        int ptr=0;
        for(int i=0;i<arr2.size();i++)
        {
            int idx=upper_bound(arr1.begin()+ptr,arr1.end(),arr2[i])-arr1.begin();
            if(idx==ptr)
                continue;
            idx--;
            ans+=1LL*(idx-ptr+1)*arr2[i]-pre[idx];
            if(ptr-1>=0)
                ans+=pre[ptr-1];
            ptr=idx+1;
        }
        if(ptr<arr1.size())
            return LLONG_MAX;
        return ans;
    }

    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(),packages.end());
        for(auto& arr : boxes)
            sort(arr.begin(),arr.end());
        vector<ll>pre(packages.size());
        pre[0]=packages[0];
        for(int i=1;i<packages.size();i++)
            pre[i]=pre[i-1]+packages[i];    
        ll ans=LLONG_MAX;
        for(auto& arr2 : boxes)
            ans=min(ans,waste(packages,arr2,pre));
        if(ans==LLONG_MAX)
            return -1;
        return ans%mod;
    }
};