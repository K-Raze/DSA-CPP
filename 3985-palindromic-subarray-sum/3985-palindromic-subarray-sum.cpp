using ll=long long;
using pll=pair<ll,ll>;
class Solution {
public:

    class RollingHash
    {
        public : 
        int n;
        const ll b1=131,b2=137;
        const ll mod1=1e9+7,mod2=1e9+9;
        vector<ll>pow1,pow2;
        vector<ll>pre1,pre2;

        RollingHash(vector<int>& s)
        {
            n=s.size();
            pow1.assign(n+1,1);
            pow2.assign(n+1,1);
            for(int i=1;i<=n;i++)
            {
                pow1[i]=(pow1[i-1]*b1)%mod1;
                pow2[i]=(pow2[i-1]*b2)%mod2;
            }

            pre1.assign(n,1);
            pre2.assign(n,1);
            pre1[0]=s[0];
            pre2[0]=s[0];
            for(int i=1;i<n;i++)
            {
                pre1[i]=((pre1[i-1]*b1)%mod1+s[i])%mod1;
                pre2[i]=((pre2[i-1]*b2)%mod2+s[i])%mod2;
            }
        }

        pll getHash(int l,int r)
        {
            int len=r-l+1;
            ll h1=pre1[r];
            if(l-1>=0)
                h1-=(pow1[len]*pre1[l-1])%mod1;
            h1 += mod1;
            if(h1 >= mod1)
                h1 -= mod1;
            ll h2=pre2[r];
            if(l-1>=0)
                h2-=(pow2[len]*pre2[l-1])%mod2;
            h2 += mod2;
            if(h2 >= mod2)
                h2 -= mod2;
            return {h1,h2};
        }
    };

    long long getSum(vector<int>& arr)
    {
        int n=arr.size();

        vector<ll> pre(n);
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+arr[i];

        RollingHash rh1(arr);

        vector<int> rev=arr;
        reverse(rev.begin(),rev.end());
        RollingHash rh2(rev);

        ll ans=0;

        // odd
        for(int i=0;i<n;i++)
        {
            int start=1,end=min(i+1,n-i);
            int best=0;

            while(start<=end)
            {
                int mid=start+((end-start)>>1);

                int l1=i-mid+1;
                int r1=i+mid-1;

                int l2=n-r1-1;
                int r2=n-l1-1;

                if(rh1.getHash(l1,r1)==rh2.getHash(l2,r2))
                {
                    best=mid;
                    start=mid+1;
                }
                else
                    end=mid-1;
            }

            if(best)
            {
                int l=i-best+1;
                int r=i+best-1;

                ll temp=pre[r];
                if(l-1>=0)
                    temp-=pre[l-1];

                ans=max(ans,temp);
            }
        }

        // even
        for(int i=0;i+1<n;i++)
        {
            int start=1,end=min(i+1,n-i-1);
            int best=0;

            while(start<=end)
            {
                int mid=start+((end-start)>>1);

                int l1=i-mid+1;
                int r1=i+mid;

                int l2=n-r1-1;
                int r2=n-l1-1;

                if(rh1.getHash(l1,r1)==rh2.getHash(l2,r2))
                {
                    best=mid;
                    start=mid+1;
                }
                else
                    end=mid-1;
            }

            if(best)
            {
                int l=i-best+1;
                int r=i+best;

                ll temp=pre[r];
                if(l-1>=0)
                    temp-=pre[l-1];

                ans=max(ans,temp);
            }
        }

        return ans;
    }
};