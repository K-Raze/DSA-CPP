class Solution {
public:

    // 0-2-3-1-4


    // B->R x 
    // W->B x 
    // R->W x 
    // same also not allowed hojayega 
    // its like dfs me ek edge valid h to uske niche mt ja !
    // rerooting dp
    
    // deg for every node <=3 and root cant have degree 3 

    string color;
    vector<vector<int>>adj;
    vector<int>degree;

    bool isColorValid(int a,int b)
    {
        if(a==-1 || b==-1)
            return 1;
        char c1=color[a],c2=color[b];
        if(c1==c2)
            return 0;
        if(c1=='B' && c2=='R')
            return 0;
        else if(c1=='W' && c2=='B')
            return 0;
        else if(c1=='R' && c2=='W')
            return 0;
        return 1;
    }
    
    vector<bool>dfGood;

    bool dfs1(int x,int par) // down flow check only
    {
        // down flow check
        int df=1;
        for(int& y : adj[x])
            if(y!=par && !isColorValid(x,y))
                df=0;
        for(int& y : adj[x])
            if(y!=par)
                df&=dfs1(y,x);
        return dfGood[x]=df;
    }

    int ans;

    void dfs2(int x,int par,bool uf)
    {
        // can this be parent ? 
        if(uf && dfGood[x] && degree[x]<3)
        {
            ans=x;
            return;
        }
        // niche ja 
        if(!uf)
            return;
        
        for(int& y : adj[x])
            if(y!=par && isColorValid(y,x))
            {
                bool nuf=1;
                for(int& z : adj[x])
                    if(z!=par && z!=y)
                    {
                        nuf&=isColorValid(x,z);
                        nuf&=dfGood[z];
                    }
                dfs2(y,x,nuf);
            }
    }
    
    int findColoredRoot(vector<vector<int>>& edges, string c) {
        color=c;
        int n=c.size();
        adj.assign(n,{});
        degree.assign(n,0);
        for(auto& it : edges)
            {
                degree[it[0]]++;
                degree[it[1]]++;
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        for(int x : degree)
            if(x>3)
                return -1;
        ans=-1;
        dfGood.assign(n,0);
        for(int i=0;i<n;i++)
            if(degree[i]<3)
            {
                dfs1(i,-1);
                dfs2(i,-1,1);
                break;
            }
        return ans;
    }
};