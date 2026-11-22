using ll=long long;
class Solution {
public:
    long long minCost(vector<int>& arr) {
        int n=arr.size();
        ll ans=LLONG_MAX;

        ll l=0;
        for(int i=1;i<n;i++)
        {
            if(arr[l]==arr[i])
                continue;
            else
            {
                ll r=i-1;
                if(l==0 && r!=0)
                {
                    ll cost=(n-r-1)*arr[l];
                    ans=min(ans,cost);
                }
                else if(r!=0)
                {
                    ll cost=l*arr[l]+(n-r-1)*arr[l];
                    ans=min(ans,cost);
                }
                l=i;
            }
        }
        if(l!=n-1)
            ans=min(ans,l*arr[l]);
        return ans;
    }
};