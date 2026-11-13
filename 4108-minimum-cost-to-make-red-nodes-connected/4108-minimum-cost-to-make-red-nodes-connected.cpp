using ll=long long;
ll dp[100005][2][2];
class Solution {
public:

    vector<ll>subSize;
    vector<vector<int>>adj;

    void init(int x,int par)
    {
        subSize[x]=1;
        for(int& y : adj[x])
            if(y!=par)
            {
                init(y,x);
                subSize[x]+=subSize[y];
            }
    }

    // if curr ko me red kru to children ksh bhi ho skte h 
    // if curr ko me blue kru to 

    ll solve(int x,int par,bool upRed,bool flow,string& color)
    {
        if(dp[x][upRed][flow]!=-1)
            return dp[x][upRed][flow];
        ll ans=LLONG_MAX;
        if(upRed)
        {
            if(flow)
            {
                // make red
                {
                    ll temp=0;
                    if(color[x]!='R')
                        temp+=subSize[x];
                    for(int& y : adj[x])
                        if(y!=par)
                            temp+=solve(y,x,1,1,color);
                    ans=min(ans,temp);
                }
                // dont make red
                {
                    ll temp=0;
                    if(color[x]!='B')
                        temp+=subSize[x];
                    for(int& y : adj[x])
                        if(y!=par)
                            temp+=solve(y,x,1,0,color);
                    ans=min(ans,temp);
                }
            }
            else
            {
                ll temp=0;
                if(color[x]!='B')
                    temp+=subSize[x];
                for(int& y : adj[x])
                    if(y!=par)
                        temp+=solve(y,x,1,0,color);
                ans=min(ans,temp);
            }
        }
        else
        {
            // make it red
            {
                ll temp=0;
                if(color[x]!='R')
                    temp+=subSize[x];
                for(int& y : adj[x])
                    if(y!=par)
                        temp+=solve(y,x,1,1,color);
                ans=min(ans,temp);
            }
            // dont make it red
            ll total=0;
            if(color[x]!='B')
                total+=subSize[x];
            // make any 1 option to be anything and rest blue
            for(int& y : adj[x])
                if(y!=par)
                    total+=solve(y,x,1,0,color);
            ans=min(ans,total);

            for(int& y : adj[x])
                if(y!=par)
                {
                    total-=solve(y,x,1,0,color);
                    total+=solve(y,x,0,0,color);
                    ans=min(ans,total);
                    total+=solve(y,x,1,0,color);
                    total-=solve(y,x,0,0,color);
                }
        }
        return dp[x][upRed][flow]=ans;
    }

    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        subSize.assign(n,0);

        adj.assign(n,{});
        for(auto& it : edges )
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        init(0,-1);
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,0,0,colors);
    }
};