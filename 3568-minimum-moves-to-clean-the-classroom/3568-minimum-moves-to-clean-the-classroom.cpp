bool vis[21][21][51][1024];
const int inf=2e9;
class Solution {
public:

    int n,m;
    int r[4]={0,0,1,-1};
    int c[4]={1,-1,0,0};

    inline bool isValid(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }


    const int inf=2e9;

    int minMoves(vector<string>& mat, int E) {
        n=mat.size();
        m=mat[0].size();

        vector<vector<int>> cordBit(n, vector<int>(m, -1));
        int tl;
        {
            int bit=0;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(mat[i][j]=='L')
                        cordBit[i][j]=bit++;
            tl=bit;
        }
        if(!tl)
            return 0;

        int fullMask = (1 << tl) - 1;
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    for(int e=0;e<=E;e++)
                        for(int k=0;k<=fullMask;k++)
                            vis[i][j][e][k]=0;
        }
        
        queue<array<int,5>>q;
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(mat[i][j]=='S')
                    {
                        q.push({0,E,i,j,fullMask});
                        vis[i][j][E][fullMask]=1;
                        break;
                    }
        }
        // move,energy,x,y,mask
        int ans=inf;
        while(!q.empty())
        {
            auto [move,ce,x,y,mask]=q.front();
            q.pop();
            if(!mask)
                ans=min(ans,move);
            if(!ce || !mask)
                continue;
            for(int k=0;k<4;k++)
            {
                int nx=x+r[k];
                int ny=y+c[k];
                if(isValid(nx,ny) && mat[nx][ny]!='X')
                {
                    int ne=ce-1;
                    int nMask=mask;
                    if(mat[nx][ny]=='L')
                    {
                        int bit=cordBit[nx][ny];
                        nMask = mask & ~(1 << bit);
                    }
                    else if(mat[nx][ny]=='R')
                        ne=E;

                    if(!vis[nx][ny][ne][nMask])
                    {
                        vis[nx][ny][ne][nMask]=1;
                        q.push({move+1,ne,nx,ny,nMask});
                    }
                }
            }
        }
        if(ans==inf)
            return -1;
        return ans;
    }
};