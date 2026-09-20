// +a -b +c -d
// +b -c +d -a

// +a -b +c 
// +b -c +a 

using ll=long long;
const ll ninf=-4e18;
ll dp[2][2][2][2][100005];
bool vis[2][2][2][2][100005];
class Solution {
public:

    ll solve(int x,bool rot,bool on,bool sp,bool st,vector<int>& arr)
    {
        if(x==arr.size())
        {
            if(rot)
            {
                if((x&1)==sp)
                    return 0;
                return ninf;
            }
            return 0;
        }
        if(vis[rot][on][sp][st][x])
            return dp[rot][on][sp][st][x];
        vis[rot][on][sp][st][x]=1;
        ll ans=-4e18;
        bool par=((x&1)^rot);
        ll val= par ? -arr[x] : arr[x];
        if(rot)
        {
            // stop rot
            if((x&1)==sp)
                ans=max(ans,solve(x,0,1,0,0,arr));
            // go with it
            if(st)
                ans=max(ans,((x&1) ? -arr[x] : arr[x])+solve(x+1,1,1,sp,0,arr));
            else
                ans=max(ans,val+solve(x+1,1,1,sp,0,arr));
        }
        else
        {
            // on rot
            if(!on)
            {
                // odd len bna
                ans=max(ans,solve(x,1,1,1-(x&1),1,arr));
                // even len bna
                ans=max(ans,solve(x,1,1,(x&1),0,arr));
            }
            // go with it
            ans=max(ans,val+solve(x+1,0,on,0,0,arr));
        }
        return dp[rot][on][sp][st][x]=ans;
    }
    
    long long maxValue(vector<int>& arr) {
        memset(vis,0,sizeof(vis));
        return solve(0,0,0,0,0,arr);
    }
};