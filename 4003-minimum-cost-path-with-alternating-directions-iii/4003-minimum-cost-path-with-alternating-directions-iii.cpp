using ll=long long;
const ll inf=4e18;
class Solution {
public:

    // 0 2 right or down
    // 1 3 vv

    int r[4]={0,0,1,-1};
    int c[4]={1,-1,0,0};

    inline bool isValid(int x,int y,int n,int m)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }

    long long minCost(int n, int m, vector<vector<int>>& penalty) {
        vector<vector<array<ll,2>>> dis(n, vector<array<ll,2>>(m, {inf, inf}));
        priority_queue<tuple<ll,ll,ll,bool>,vector<tuple<ll,ll,ll,bool>>,greater<tuple<ll,ll,ll,bool>>>pq;
        pq.push({1,0,0,1});
        dis[0][0][1]=1;
        while(!pq.empty())
        {
            auto[val,x,y,par]=pq.top();
            pq.pop();
            if(x==n-1 && y==m-1)
                return val;
            if(val!=dis[x][y][par])
                continue;

            if(dis[x][y][1-par]>val+penalty[x][y])
            {
                dis[x][y][1-par]=val+penalty[x][y];
                pq.push({val+penalty[x][y],x,y,1-par});
            }

            for(int k=0;k<4;k++)
            {
                int nx=x+r[k];
                int ny=y+c[k];
                if(!isValid(nx,ny,n,m))
                    continue;
                
                bool npar=1-par;

                ll newVal=(nx+1)*(ny+1)+val;
                
                if(par&1)
                {
                    if(k&1)
                        newVal+=penalty[x][y];
                }
                else
                {
                    if(!(k&1))
                        newVal+=penalty[x][y];
                }

                if(newVal<dis[nx][ny][npar])
                {
                    dis[nx][ny][npar]=newVal;
                    pq.push({newVal,nx,ny,npar});
                }
            }
        }
        return -1;
    }
};