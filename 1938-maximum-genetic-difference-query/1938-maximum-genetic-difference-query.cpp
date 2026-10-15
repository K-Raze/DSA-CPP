class Solution {
public:

    // har node pe {val,idx} dalde

    class node
    {
        public : 
        node* child[2];
        int cnt;
        node()
        {
            child[0]=child[1]=NULL;
            cnt=0;
        }
    };

    void insert(node* curr,int bit,int val)
    {
        curr->cnt++;
        if(bit==-1)
            return;
        bool path=((val>>bit)&1);
        if(!curr->child[path])
            curr->child[path]=new node();
        insert(curr->child[path],bit-1,val);
    }

    void rem(node* curr,int bit,int val)
    {
        if(curr->cnt)
            curr->cnt--;
        if(bit==-1)
            return;
        bool path=((val>>bit)&1);
        rem(curr->child[path],bit-1,val);
    }

    int query(node* curr,int bit,int val)
    {
        if(bit==-1)
            return 0;
        bool path=!((val>>bit)&1);
        int ans=0;
        if(curr->child[path] && curr->child[path]->cnt)
            ans+=(1<<bit);
        else
            path=1-path;
        ans+=query(curr->child[path],bit-1,val);
        return ans;
    }

    vector<vector<int>>adj;
    vector<int>ans;
    vector<vector<pair<int,int>>>nodeQuery; // xi,idx

    void dfs(int x,node* root)
    {
        insert(root,30,x);

        // queries kr
        for(auto&[val,idx] : nodeQuery[x])
            ans[idx]=query(root,30,val);
        
        // childs pe ja
        for(int& y : adj[x])
            dfs(y,root);

        rem(root,30,x);
    }

    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n=parents.size();

        adj.assign(n,{});
        int start;
        for(int i=0;i<n;i++)
        {
            if(parents[i]!=-1)
                adj[parents[i]].push_back(i);
            else
                start=i;
        }
        
        ans.resize(queries.size());
        nodeQuery.assign(n,{});
        for(int i=0;i<queries.size();i++)
        {
            int u=queries[i][0],x=queries[i][1];
            nodeQuery[u].push_back({x,i});
        }

        node* root = new node();
        dfs(start,root);
        return ans;
    }
};