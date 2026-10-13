using ll=long long;
class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        ll start=1,end=1e17;

        while(start<=end)
        {
            ll num=start+((end-start)>>1);

            ll sum=0;

            for(int bit=60;bit>=0;bit--)
                if((bit+1)%x==0)
                {
                    ll div=(1LL<<(bit+1));
                    sum+=1LL*((num+1)/div)*(1LL<<bit);
                    sum+=max(0LL,((num+1)%div)-(1LL<<bit));
                }
            
            if(sum<=k)
                start=num+1;
            else
                end=num-1;
        }
        
        return end;
    }
};