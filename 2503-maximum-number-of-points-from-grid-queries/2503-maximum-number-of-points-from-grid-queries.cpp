class Solution {
public:

    vector<int> parentDsu, sizeDsu;

    void dsuInit(int n)
    {
        parentDsu.resize(n);
        sizeDsu.assign(n, 1);

        for(int i=0;i<n;i++)
            parentDsu[i]=i;
    }

    int ultParent(int x)
    {
        return x==parentDsu[x]
               ? x
               : parentDsu[x]=ultParent(parentDsu[x]);
    }

    void unionBySize(int a,int b)
    {
        a=ultParent(a);
        b=ultParent(b);

        if(a==b)
            return;

        if(sizeDsu[a]<sizeDsu[b])
            swap(a,b);

        parentDsu[b]=a;
        sizeDsu[a]+=sizeDsu[b];
    }

    int n,m;

    int r[4]={0,0,1,-1};
    int c[4]={1,-1,0,0};

    inline bool isValid(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }

    vector<int> maxPoints(vector<vector<int>>& mat,
                          vector<int>& queries)
    {
        vector<pair<int,int>> q;

        for(int i=0;i<queries.size();i++)
            q.push_back({queries[i],i});

        sort(q.begin(),q.end());

        n=mat.size();
        m=mat[0].size();

        vector<array<int,3>> arr;

        int gi=0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                arr.push_back({mat[i][j],i,j});
                mat[i][j]=gi++;
            }

        sort(arr.begin(),arr.end());
        dsuInit(gi);

        vector<bool> active(gi,false);

        int ptr=0;
        vector<int> ans(queries.size());

        for(auto& [val,idx] : q)
        {
            while(ptr<arr.size() && arr[ptr][0]<val)
            {
                int x=arr[ptr][1];
                int y=arr[ptr][2];

                int id=mat[x][y];
                active[id]=true;

                for(int k=0;k<4;k++)
                {
                    int nx=x+r[k];
                    int ny=y+c[k];

                    if(isValid(nx,ny))
                    {
                        int nid=mat[nx][ny];
                        if(active[nid])
                            unionBySize(id,nid);
                    }
                }
                ptr++;
            }

            int start=mat[0][0];

            if(!active[start])
                ans[idx]=0;
            else
            {
                int par=ultParent(start);
                ans[idx]=sizeDsu[par];
            }
        }

        return ans;
    }
};