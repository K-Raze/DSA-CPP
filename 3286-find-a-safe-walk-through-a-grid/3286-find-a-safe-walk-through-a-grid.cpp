class Solution {
public:

    int r[4]={0,0,1,-1};
    int c[4]={1,-1,0,0};

    int n,m;

    inline bool isValid(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }

    bool findSafeWalk(vector<vector<int>>& mat, int health) {
        n=mat.size();
        m=mat[0].size();

        vector<vector<int>>healthCell(n,vector<int>(m,-1));

        deque<pair<int,int>>dq;
        dq.push_front({0,0});
        healthCell[0][0]=health-mat[0][0];

        while(!dq.empty())
        {
            auto[x,y]=dq.front();
            dq.pop_front();
            if(x==n-1 && y==m-1)
                return healthCell[x][y]>=1;
            if(!healthCell[x][y])
                return 0;
            
            for(int k=0;k<4;k++)
            {
                int nx=x+r[k];
                int ny=y+c[k];
                if(isValid(nx,ny) && healthCell[nx][ny]==-1)
                {
                    healthCell[nx][ny]=healthCell[x][y]-mat[nx][ny];
                    if(mat[nx][ny])
                        dq.push_back({nx,ny});
                    else
                        dq.push_front({nx,ny});
                }
            }
        }
        return 0;
    }
};