using ll=long long;
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        vector<pair<ll,ll>>arr(n);
        for(int i=0;i<n;i++)
            arr[i]={nums[i],cost[i]};
        
        sort(arr.begin(),arr.end());
        vector<ll>pre;
        {
            ll costAc=0;
            ll curr=0;
            ll last=arr.front().first;
            for(auto&[v,c] : arr)
            {
                ll diff=v-last;
                curr+=costAc*diff;
                pre.push_back(curr);
                costAc+=c;
                last=v;
            }
        }
        vector<ll>suff;
        {
            reverse(arr.begin(),arr.end());
            ll costAc=0;
            ll curr=0;
            ll last=arr.front().first;
            for(auto&[v,c] : arr)
            {
                ll diff=last-v;
                curr+=costAc*diff;
                suff.push_back(curr);
                costAc+=c;
                last=v;
            }
            reverse(suff.begin(),suff.end());
        }
        ll ans=LLONG_MAX;
        for(int i=0;i<n;i++)
            ans=min(ans,pre[i]+suff[i]);
        return ans;
    }
};