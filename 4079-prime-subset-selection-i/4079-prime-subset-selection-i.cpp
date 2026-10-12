bool done=0;
const int mn=1e6;
bool isPrime[mn+1];
using ll=long long;

void sieve()
    {
        if(done)
            return;
        if(!done)
            done=1;
        memset(isPrime,1,sizeof(isPrime));
        isPrime[1]=0;
        for(ll i=2;i<=mn;i++)
            for(ll j=1LL*i*i;j<=mn;j+=i)
                isPrime[j]=0;
    }

class Solution {
public:
    
    
    vector<int> maxPrimes(int n, int s) {
        sieve();
        vector<int>ans;
        ll sum=0;
        for(int val=1;val<=n && sum+val<=s;val++)
        {
            // cout<<val<<" "<<isPrime[val]<<endl;
            if(isPrime[val])
            {
                sum+=val;
                ans.push_back(val);
            }
        }
        return ans;
    }
};