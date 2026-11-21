class Solution {
public:

    vector<vector<int>>adj;
    vector<vector<int>>nAdj;

    bool make(int x,vector<vector<int>>& anc,string& s)
    {
        auto& arr=anc[s[x]-'a'];
        bool ret=0;
        if(!arr.empty())
        {
            ret=1;
            nAdj[arr.back()].push_back(x);
        }
        // cout<<x<<" "<<ret<<endl;
        arr.push_back(x);

        for(int& y : adj[x])
            if(!make(y,anc,s))  
                nAdj[x].push_back(y);

        arr.pop_back();
        return ret;
    }

    vector<int>ans;

    void dfs(int x)
    {
        ans[x]=1;
        for(int& y : nAdj[x])
        {
            dfs(y);
            ans[x]+=ans[y];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();

        adj.resize(n);
        ans.resize(n);
        nAdj.resize(n);

        for(int i=1;i<n;i++)
            adj[parent[i]].push_back(i);

        
        vector<vector<int>>anc(26);
        make(0,anc,s);
        dfs(0);
        return ans;
    }
};