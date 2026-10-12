using ll=long long;
const ll inf=4e18;
class Solution {
public:

    vector<bool>isPrime;
    void sieve(int mn)
    {
        isPrime.assign(mn+1,1);
        isPrime[1]=0;
        for(ll i=2;i<=mn;i++)
            for(ll j=1LL*i*i;j<=mn;j+=i)
                isPrime[j]=0;
    }

    ll findMaxSum(int val,int sum,int s,int n,
                 vector<vector<ll>>& dp)
    {
        if(val>n || val+sum>s)
            return 0;
        if(dp[val][sum]!=-1)
            return dp[val][sum];
        // skip
        ll ans=findMaxSum(val+1,sum,s,n,dp);
        // take
        if(isPrime[val])
            ans=max(ans,val+findMaxSum(val+1,sum+val,s,n,dp));
        return dp[val][sum]=ans;
    }

    
    ll fewLexo(int val,int sum,int s,int n,
              vector<vector<ll>>& dp,vector<vector<bool>>& track)
    {
        if(sum==s)
            return 0;
        if(val>n || val+sum>s)
            return inf;
        if(dp[val][sum]!=-1)
            return dp[val][sum];
        // skip
        ll val1=fewLexo(val+1,sum,s,n,dp,track);
        // take
        ll val2=inf;
        if(isPrime[val])
            val2=1+fewLexo(val+1,sum+val,s,n,dp,track);

        if(val1>=val2)
            track[val][sum]=1;
        
        return dp[val][sum]=min(val1,val2);
    }
    
    vector<int> maxPrimeSubset(int n, int s) {
        sieve(n);

        ll maxSum;
        {
            vector<vector<ll>>dp(n+2,vector<ll>(s+2,-1));
            maxSum=findMaxSum(1,0,s,n,dp);
        }
        ll elem;
        vector<vector<bool>>track(n+2,vector<bool>(maxSum+2,0));
        {
            vector<vector<ll>>dp(n+2,vector<ll>(maxSum+2,-1));
            elem=fewLexo(1,0,maxSum,n,dp,track);
        }
        if(!elem)
            return {};
        
        // track
        vector<int>ans;
        int val=1, sum=0;
        while(sum!=maxSum)
        {
            // cout<<val<<" "<<sum<<" "<<track[val][sum]<<endl;
            if(track[val][sum])
            {
                ans.push_back(val);
                sum+=val;
            }
            val++;
        }
        return ans;
    }
};