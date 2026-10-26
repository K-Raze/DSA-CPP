class Solution {
public:

    // e<-d<-a->b->c
    // c b e d a

    void giveTopo(int x,vector<vector<int>>& adj,vector<int>& st,vector<bool>& vis)
    {
        vis[x]=1;
        for(int& y : adj[x])
            if(!vis[y])
                giveTopo(y,adj,st,vis);
        st.push_back(x);
    }

    unordered_map<int,int>parSz;
    vector<int>parTopo;
    void assignParDfs(int x,vector<vector<int>>& adj,vector<bool>& vis,vector<int>& par,int p)
    {
        parSz[p]++;
        vis[x]=1;
        par[x]=p;
        for(int& y : adj[x])
            if(!vis[y])
                assignParDfs(y,adj,vis,par,p);
    }

    vector<int>givePar(vector<int>& edges)
    {
        int n=edges.size();

        vector<int>tSort;
        {
            vector<vector<int>>adj(n);
            for(int p=0;p<n;p++)
                adj[p].push_back(edges[p]);
            
            {
                vector<bool>vis(n,0);
                for(int i=0;i<n;i++)
                    if(!vis[i])
                        giveTopo(i,adj,tSort,vis);
                reverse(tSort.begin(),tSort.end());
            }
        }
        vector<int>par(n);
        {
            vector<vector<int>>adj(n);
            for(int p=0;p<n;p++)
                adj[edges[p]].push_back(p);
            {
                vector<bool>vis(n,0);
                for(int i : tSort)
                {
                    if(!vis[i])
                        assignParDfs(i,adj,vis,par,i);
                    // cout<<i<<" "<<par[i]<<" "<<endl;
                }
            }
        }

        reverse(tSort.begin(),tSort.end());
        for(int i : tSort)
        {
            // cout<<i<<" ";
            i=par[i];
            if(parTopo.empty() || (parTopo.back()!=i))
                parTopo.push_back(i);
        }

        return par;
    }

    /////////////////// upar wale fxn ek sath kam krre h 

    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        parSz.clear();
        parTopo.clear();
        vector<int>par=givePar(edges);

        // push dp lgade ab haff 
        vector<unordered_set<int>>adj(n);
        for(int p=0;p<n;p++)
            adj[par[edges[p]]].insert(par[p]);
        vector<int>dp(n);
        for(int& x : parTopo)
            dp[x]=parSz[x];
        for(int& x : parTopo)
            for(int y : adj[x])
                if(y!=x)
                    dp[y]+=dp[x];
        vector<int>ans(n);
        for(int i=0;i<n;i++)
            ans[i]=dp[par[i]];
        return ans;
    }
};