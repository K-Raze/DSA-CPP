using pii=pair<int,int>;
class Solution {
public: 

    // bfs
    // bs on ans

    int n,m;

    int r[4]={0,0,1,-1};
    int c[4]={1,-1,0,0};

    inline bool isValid(int x,int y)
    {
        return x>=0 && x<n && y>=0 && y<m;
    }

    void bfs(vector<vector<int>>& mat)
    {
        queue<pii>q;
        vector<vector<int>>dis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j])
                {
                    q.push({i,j});
                    dis[i][j]=0;
                }
        while(!q.empty())
        {
            auto[x,y]=q.front();
            q.pop();

            for(int k=0;k<4;k++)
            {
                int nx=x+r[k],ny=y+c[k];
                if(isValid(nx,ny) && dis[nx][ny]==-1)
                {
                    dis[nx][ny]=dis[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        mat=dis;
    }

    bool solve(int x,int y,int minDis,vector<vector<int>>& mat,
            vector<vector<int>>& vis)
    {
        if(mat[x][y] < minDis)
             return 0;
        if(x==n-1 && y==m-1)
            return 1;
        vis[x][y]=1;
        for(int k=0;k<4;k++)
        {
            int nx=x+r[k], ny=y+c[k];
            if(isValid(nx,ny) && !vis[nx][ny])
                if(solve(nx,ny,minDis,mat,vis))
                    return 1;
        }
        return 0;
    }

    int maximumSafenessFactor(vector<vector<int>>& mat) {
        n=mat.size(),m=mat[0].size();
        bfs(mat);
        int start=0,end=805;
        while(start<=end)
        {
            int mid=start+((end-start)>>1);
            vector<vector<int>> vis(n, vector<int>(m,0));
            if(solve(0,0,mid,mat,vis))
                start=mid+1;
            else
                end=mid-1;
        }
        return end;
    }
};