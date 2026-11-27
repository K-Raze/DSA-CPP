class Solution {
public:

    int r[4]={0,0,1,-1};
    int c[4]={1,-1,0,0};

    int n,m;

    inline bool isValid(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }

    inline bool check(int wait,
        vector<vector<int>>& mat,vector<vector<int>>& fireDis)
    {
        if(wait>=fireDis[0][0])
            return 0;
        
        queue<pair<int,int>>q;
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        q.push({0,0});
        dis[0][0]=wait;
        
        while(!q.empty())
            {
                auto[x,y]=q.front();
                q.pop();
                
                if(x==n-1 && y==m-1)
                    return 1;

                for(int k=0;k<4;k++)
                {
                    int nx=x+r[k];
                    int ny=y+c[k];
                    if(!isValid(nx,ny) || mat[nx][ny]==2 || dis[nx][ny]!=INT_MAX)
                        continue;

                    int nextTime = dis[x][y] + 1;

                    if (nx == n - 1 && ny == m - 1 && nextTime <= fireDis[nx][ny])
                        return 1;

                    if (nextTime >= fireDis[nx][ny])
                        continue;
                    
                    dis[nx][ny]=1+dis[x][y];
                    q.push({nx,ny});
                }
            }
        return 0;
    }

    // simple binary search + bfs

    int maximumMinutes(vector<vector<int>>& mat) {
        n=mat.size(),m=mat[0].size();

        // find fireDis 
        vector<vector<int>>fireDis(n,vector<int>(m,INT_MAX));
        {   
            queue<pair<int,int>>q;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(mat[i][j]==1)
                    {
                        q.push({i,j});
                        fireDis[i][j]=0;
                    }
            
            while(!q.empty())
            {
                auto[x,y]=q.front();
                q.pop();

                for(int k=0;k<4;k++)
                {
                    int nx=x+r[k];
                    int ny=y+c[k];
                    if(!isValid(nx,ny) || mat[nx][ny]==2 || fireDis[nx][ny]!=INT_MAX)
                        continue;
                    
                    fireDis[nx][ny]=1+fireDis[x][y];
                    q.push({nx,ny});
                }
            }
        }

        int start=0,end=1e9;

        while(start<=end)
        {
            int mid=start+((end-start)>>1);
            if(check(mid,mat,fireDis))
                start=mid+1;
            else
                end=mid-1;
        }
        return end;
    }
};