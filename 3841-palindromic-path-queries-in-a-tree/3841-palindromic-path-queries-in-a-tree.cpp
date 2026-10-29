class Segment {
public:

    vector<int> tree,lazy;
    int n;

    void init(int sz)
    {
        n=sz;
        tree.assign(4*n,0);
        lazy.assign(4*n,0);
    }

    void build(int node,int l,int r,vector<int>& arr)
    {
        if(l==r)
        {
            tree[node]=arr[l];
            return;
        }

        int mid=(l+r)/2;

        build(2*node,l,mid,arr);
        build(2*node+1,mid+1,r,arr);

        tree[node]=tree[2*node]^tree[2*node+1];
    }

    void apply(int node,int l,int r,int val)
    {
        if((r-l+1)&1)
            tree[node]^=val;

        lazy[node]^=val;
    }

    void push(int node,int l,int r)
    {
        if(lazy[node]==0 || l==r)
            return;

        int mid=(l+r)/2;

        apply(2*node,l,mid,lazy[node]);
        apply(2*node+1,mid+1,r,lazy[node]);

        lazy[node]=0;
    }

    void update(int node,int l,int r,int ql,int qr,int val)
    {
        if(qr<l || r<ql)
            return;

        if(ql<=l && r<=qr)
        {
            apply(node,l,r,val);
            return;
        }

        push(node,l,r);

        int mid=(l+r)/2;

        update(2*node,l,mid,ql,qr,val);
        update(2*node+1,mid+1,r,ql,qr,val);

        tree[node]=tree[2*node]^tree[2*node+1];
    }

    int query(int node,int l,int r,int idx)
    {
        if(l==r)
            return tree[node];

        push(node,l,r);

        int mid=(l+r)/2;

        if(idx<=mid)
            return query(2*node,l,mid,idx);

        return query(2*node+1,mid+1,r,idx);
    }
};

class Solution {
public:

    vector<vector<int>> adj,up;
    vector<int> depth,inTime,outTime,xorPath;
    string nodeChars;

    int timer,LOG;
    Segment seg;

    void buildLCA(int node,int par)
    {
        inTime[node]=timer++;

        up[node][0]=par;

        for(int j=1;j<LOG;j++)
        {
            up[node][j]=up[up[node][j-1]][j-1];
        }

        xorPath[node]=1<<(nodeChars[node]-'a');

        if(node!=par)
            xorPath[node]^=xorPath[par];

        for(int v : adj[node])
        {
            if(v==par)
                continue;

            depth[v]=depth[node]+1;

            buildLCA(v,node);
        }

        outTime[node]=timer-1;
    }

    int liftNode(int node,int dist)
    {
        if(dist==0)
            return node;

        int bit=31-__builtin_clz((unsigned int)dist);

        return liftNode(up[node][bit],dist-(1<<bit));
    }

    int queryLCARec(int u,int v,int bit)
    {
        if(u==v)
            return u;

        if(bit<0)
            return up[u][0];

        if(up[u][bit]!=up[v][bit])
            return queryLCARec(up[u][bit],up[v][bit],bit-1);

        return queryLCARec(u,v,bit-1);
    }

    int queryLCA(int u,int v)
    {
        if(depth[u]<depth[v])
            swap(u,v);

        u=liftNode(u,depth[u]-depth[v]);

        if(u==v)
            return u;

        return queryLCARec(u,v,LOG-1);
    }

    int giveXor(int u,int v)
    {
        int xorU=seg.query(1,0,(int)adj.size()-1,inTime[u]);
        int xorV=seg.query(1,0,(int)adj.size()-1,inTime[v]);

        int lca=queryLCA(u,v);

        int valLca=1<<(nodeChars[lca]-'a');

        return xorU^xorV^valLca;
    }

    vector<bool> palindromePath(int n,vector<vector<int>>& edges,string s,vector<string>& queries)
    {
        nodeChars=s;

        adj.assign(n,vector<int>());

        for(auto& edge : edges)
        {
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        LOG=20;
        timer=0;

        depth.assign(n,0);
        inTime.assign(n,0);
        outTime.assign(n,0);
        xorPath.assign(n,0);

        up.assign(n,vector<int>(LOG,0));

        buildLCA(0,0);

        vector<int> base(n,0);

        for(int i=0;i<n;i++)
        {
            base[inTime[i]]=xorPath[i];
        }

        seg.init(n);
        seg.build(1,0,n-1,base);

        vector<bool> ans;

        for(string& q : queries)
        {
            stringstream ss(q);

            string type;
            int u;

            ss>>type>>u;

            if(type=="update")
            {
                char c;
                ss>>c;

                int oldMask=1<<(nodeChars[u]-'a');
                int newMask=1<<(c-'a');

                int diff=oldMask^newMask;

                seg.update(1,0,n-1,inTime[u],outTime[u],diff);

                nodeChars[u]=c;
            }
            else
            {
                int v;
                ss>>v;

                int mask=giveXor(u,v);

                ans.push_back(mask==0 || (mask&(mask-1))==0);
            }
        }

        return ans;
    }
};