using ll=long long;
class Solution {
public:

    ll dp[2][1505][1505];

    ll solve(int l,int r,bool where,vector<int>& arr)
    {
        if(r-l+1==arr.size())
            return 0;
        if(dp[where][l][r]!=-1)
            return dp[where][l][r];
        ll rem=arr.size()-(r-l+1);
        ll ans=4e18;
        if(l==r)
        {
            // go left
            if(l-1>=0)
                ans=min(ans,(arr[l]-arr[l-1])*rem+solve(l-1,r,0,arr));
            // go right
            if(r+1<arr.size())
                ans=min(ans,(arr[r+1]-arr[r])*rem+solve(l,r+1,1,arr));
            return dp[where][l][r]=ans;
        }

        if(!where) // left pe hu
        {
            // do l
            if(l-1>=0)
                ans=min(ans,(arr[l]-arr[l-1])*rem+solve(l-1,r,0,arr));
            // do r
            if(r+1<arr.size())
                ans=min(ans,(arr[r+1]-arr[l])*rem+solve(l,r+1,1,arr));
        }
        else // right pe hu 
        {
            // do l
            if(l-1>=0)
                ans=min(ans,(arr[r]-arr[l-1])*rem+solve(l-1,r,0,arr));
            // do r
            if(r+1<arr.size())
                ans=min(ans,(arr[r+1]-arr[r])*rem+solve(l,r+1,1,arr));
        }
        return dp[where][l][r]=ans;
    }

    long long elevatorRequests(int n, int start, vector<int>& request) {
        bool isStartPre=0;
        for(int& x : request)
            if(x==start)
                isStartPre=1;
        if(!isStartPre)
        {
            request.push_back(start);
            n++;
        }
        sort(request.begin(),request.end());
        int idx=-1;
        for(int i=0;i<n;i++)
            if(request[i]==start)
            {
                idx=i;
                break;
            }
        memset(dp,-1,sizeof(dp));
        return solve(idx,idx,0,request);
    }
};