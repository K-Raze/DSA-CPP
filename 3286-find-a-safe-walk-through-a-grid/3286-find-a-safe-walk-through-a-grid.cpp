class Solution {
public:

    int n,m;

    int r[4]={1,-1,0,0};
    int c[4]={0,0,-1,1};

    bool isValid(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }


    bool findSafeWalk(vector<vector<int>>& mat, int h) {
        n=mat.size(),m=mat[0].size();

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>> cost(n,vector<int>(m,INT_MAX));
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        pq.push({mat[0][0],0,0});
        cost[0][0]=mat[0][0];
        while(!pq.empty())
        {
            auto[cs,x,y]=pq.top();
            pq.pop();
            if(cs!=cost[x][y] || vis[x][y])
                continue;
            vis[x][y]=1;
            for(int k=0;k<4;k++)
            {
                int nx=x+r[k];
                int ny=y+c[k];
                if(isValid(nx,ny) && !vis[nx][ny] && cs+mat[nx][ny]<cost[nx][ny])
                {
                    cost[nx][ny]=cs+mat[nx][ny];
                    pq.push({cost[nx][ny],nx,ny});
                }
            }
        }
        return (h-cost[n-1][m-1])>=1;
    }
};