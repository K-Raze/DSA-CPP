class Solution {
public:

    int n;

    int dp[1<<13][101];
    pair<int,int> track[1<<13][101];

    bool solve(int mask,int div,vector<int>& arr, int k)
    {
        if(mask==(1<<n)-1)
            return (div==0);

        if(dp[mask][div]!=-1)
            return dp[mask][div];


        for(int i=0;i<n;i++)
            if(!((mask>>i)&1))
            {
                string s=to_string(arr[i]);
                int len=s.size();
                int p=1;
                for(int i=1;i<=len;i++)
                    p=(p*10)%k;
                int newDiv=((div*p)%k+arr[i])%k;
                if(solve( mask | (1<<i) ,newDiv,arr,k))
                {
                    track[mask][div]={i,newDiv};
                    return dp[mask][div]=1;
                }
            }
        return dp[mask][div]=0;
    }

    vector<int> concatenatedDivisibility(vector<int>& arr, int k) {
        n=arr.size();
        sort(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        if(!solve(0,0,arr,k))
            return {};
        vector<int>ans;
        // track
        int mask=0,div=0;
        while(mask!=(1<<n)-1)
        {
            auto[idx,newDiv]=track[mask][div];
            ans.push_back(arr[idx]);
            mask=(mask | (1<<idx));
            div=newDiv;
        }
        return ans;
    }
};