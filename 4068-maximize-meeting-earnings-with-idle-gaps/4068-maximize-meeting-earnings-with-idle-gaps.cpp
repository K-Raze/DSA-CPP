using ll=long long;
ll dp[2][100005];

class Solution {
public:

    ll solve(int x,bool start,vector<array<int,3>>& arr)
    {
        if(dp[start][x]!=-1)
            return dp[start][x];
        ll ans=arr[x][2];
        // skip
        if(x+1<arr.size())
        {
            ll adder=arr[x+1][0]-arr[x][0];
            if(!start)
                adder=0;
            ans=max(ans,adder+solve(x+1,start,arr));
        }
        // take
        int low = x + 1;
        int high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low+((high-low)>>1);
            if (arr[mid][0] >= arr[x][1])
                high = mid - 1;
            else
                low = mid + 1;
        }
        int nIdx=low;
        if(nIdx<arr.size())
            ans=max(ans,arr[x][2]+arr[nIdx][0]-arr[x][1]+solve(nIdx,1,arr));
        return dp[start][x]=ans;
    }

    long long maxEarnings(vector<vector<int>>& temp) {
        vector<array<int,3>>arr;
        for(auto& it : temp)
            arr.push_back({it[0],it[1],it[2]});
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++)
            for(int start=0;start<2;start++)
                dp[start][i]=-1;
        return solve(0,0,arr);
    }
};