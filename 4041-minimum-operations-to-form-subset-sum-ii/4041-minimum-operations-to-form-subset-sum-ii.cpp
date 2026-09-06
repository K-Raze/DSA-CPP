// max 15op
int dp[102][5005];
const int inf=2e9;
class Solution {
public:
    bool get;
    int solve(int x,int sum,vector<int>& arr, int total)
    {
        if(sum==total)
        {
            get=1;
            return 0;
        }
        if(sum>total || x==arr.size())
            return inf;
        if(dp[x][sum]!=-1)
            return dp[x][sum];
        // mul
        int ans=min(solve(x+1,sum,arr,total),solve(x+1,sum+arr[x],arr,total));
        int val=arr[x];
        for(int i=1;i<=13;i++)
        {
            val<<=1;
            if(val+sum>total)
                break;
            ans=min(ans,i+solve(x+1,sum+val,arr,total));
        }
        // div
        val=arr[x];
        for(int i=1;i<=9;i++)
        {
            val>>=1;
            int temp=val;
            ans=min(ans,i+solve(x+1,sum+val,arr,total));
            for(int j=1;j<=13;j++)
            {
                temp<<=1;
                if(sum+temp>total)
                    break;
                ans=min(ans,i+j+solve(x+1,sum+temp,arr,total));
            }
            if(!val)
                break;
        }
        return dp[x][sum]=ans;
    }
    
    int minOperations(vector<int>& arr, int sum) {
        get=0;
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,arr,sum);
        if(get)
            return ans;
        return -1;
    }
};