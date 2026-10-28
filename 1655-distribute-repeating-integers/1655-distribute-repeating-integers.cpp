int dp[52][1<<10];
class Solution {
public:
    
    int meow;

    bool solve(int x,int mask,vector<int>&sumMask,vector<int>& arr,int n,int m)
    {
        if( mask == meow )
            return 1;
        if(x==n)
            return 0;
        
        if(dp[x][mask]!=-1)
            return dp[x][mask];

        // skip it
        bool ans=solve(x+1,mask,sumMask,arr,n,m);
        // take a submask
        int avail=( meow ^ mask );
        for(int sm=avail;sm>0;sm=((sm-1)&avail))
            if(sumMask[sm]<=arr[x])
                ans|=solve(x+1,mask | sm,sumMask,arr,n,m);
        return dp[x][mask]=ans;
    }

    bool canDistribute(vector<int>& arr, vector<int>& quantity) {
        // transform
        {
            unordered_map<int,int>cnt;
            for(int& x : arr)
                cnt[x]++;
            vector<int>temp;
            for(auto&[a,b] : cnt)
                temp.push_back(b);
            arr=temp;
        }
        int n=arr.size();
        int m=quantity.size();
        vector<int>sumMask(1<<m,0);
        for(int mask=1;mask<(1<<m);mask++)
            for(int i=0;i<m;i++)
                if((mask>>i)&1)
                    sumMask[mask]+=quantity[i];
        meow=(1<<m)-1;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,sumMask,arr,n,m);
    }
};