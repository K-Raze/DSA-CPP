using ll=long long;
class Solution {
public:
    long long minimumDifference(vector<int>& arr) {
        int n=arr.size();
        int k=n/3;
        vector<ll>mxr(n);
        {
            priority_queue<ll,vector<ll>,greater<ll>>pq;
            ll sum=0;
            for(int i=n-1;i>=0;i--)
            {
                if(pq.size()<k)
                {
                    pq.push(arr[i]);
                    sum+=arr[i];
                }
                else if(pq.size()==k)
                {
                    if(arr[i]>pq.top())
                    {
                        sum-=pq.top();
                        pq.pop();
                        pq.push(arr[i]);
                        sum+=arr[i];
                    }
                }
                mxr[i]=sum;
            }
        }
        priority_queue<ll>pq;
        ll sum=0;
        ll ans=4e18;
        for(int i=0;i<2*k;i++)
        {
            if(pq.size()<k)
            {
                pq.push(arr[i]);
                sum+=arr[i];
            }
            else if(pq.size()==k)
            {
                if(arr[i]<pq.top())
                {
                    sum-=pq.top();
                    pq.pop();
                    pq.push(arr[i]);
                    sum+=arr[i];
                }
            }
            if(i>=k-1)
                ans=min(ans,sum-mxr[i+1]);
        }
        return ans;
    }
};