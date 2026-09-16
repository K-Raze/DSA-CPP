class Solution {
public:

    // 2^n*E*LogV*n
    // 1024*1000(10 hojega minDis wali lele bs 2 kee bechm)*10*10

    const int inf=2e9;

    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>>dis(n,vector<int>(n,2e9));
        for(int i=0;i<n;i++)
            dis[i][i]=0;
        for(auto& it : roads)
        {
            dis[it[0]][it[1]]=min(dis[it[0]][it[1]],it[2]);
            dis[it[1]][it[0]]=dis[it[0]][it[1]];
        }
        int ans=0;
        for(int mask=0;mask<(1<<n);mask++)
        {
            auto temp=dis;
            for(int i=0;i<n;i++)
                if(!((mask>>i)&1))
                    for(int j=0;j<n;j++)
                        temp[i][j]=inf;

            for(int m=0;m<n;m++)
                for(int u=0;u<n;u++)
                    for(int v=0;v<n;v++)
                        if(temp[u][m]!=inf && temp[m][v]!=inf)
                            temp[u][v]=min(temp[u][v],temp[u][m]+temp[m][v]);

            bool good=1;
            for(int i=0;i<n;i++)
                if((mask>>i)&1)
                    for(int j=0;j<n;j++)
                        if((mask>>j)&1)
                            if(temp[i][j]>maxDistance)
                            {
                                good=0;
                                break;
                            }
            ans+=good;
        }
        return ans;
    }
};