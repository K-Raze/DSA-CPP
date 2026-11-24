int dp[100005];
bool vis[100005];
class Solution {
public:

    vector<vector<int>>adj;

    int solve(int x,int par,vector<int>& op, vector<int>& score)
    {
        if(vis[x])
            return dp[x];
        vis[x]=1;
        int ans=INT_MIN;
        int sum=0;
        bool run=0;
        for(int& y : adj[x])
            if(y!=par)
            {
                run=1;
                sum+=solve(y,x,op,score);
            }
        if(!run)
        {
            // cout<<x<<" "<<score[x]<<endl;
            return dp[x]=score[x];
        }
        if(!op[x])
            ans=max(ans,score[x]+sum);
        for(int& y : adj[x])
            if(y!=par)
            {
                sum-=solve(y,x,op,score);
                ans=max(ans,score[x]+sum);
                sum+=solve(y,x,op,score);
            }
        // cout<<x<<" "<<ans<<endl;
        return dp[x]=ans;
    }

    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n=parent.size();
        adj.resize(n);
        for(int i=1;i<n;i++)
        {
            int p=parent[i];
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
        memset(vis,0,sizeof(vis));
        return solve(0,-1,op,score);
    }
};