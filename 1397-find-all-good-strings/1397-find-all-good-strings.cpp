const int mod=1e9+7;
int dp[505][55][2][2];
class Solution {
public:

    // abcab

    vector<int>lps;

    int solve(int x,int y,bool sUp,bool sDown,string& s1, string& s2, string& evil)
    {
        if(y==evil.size())
            return 0;
        if(x==s1.size())
            return 1;
        
        if(dp[x][y][sUp][sDown]!=-1)
            return dp[x][y][sUp][sDown];

        char l= (sDown) ? s1[x] : 'a' ;
        char r= (sUp) ? s2[x] : 'z' ;
        int ans=0;
        for(char ch=l;ch<=r;ch++)
        {
            bool nsUp=(sUp && ch==r);
            bool nsDown=(sDown && ch==l);

            int ny=y;
            while(ny>0 && evil[ny]!=ch)
                ny=lps[ny-1];
            if(evil[ny]==ch)
                ny++;

            ans=(ans+solve(x+1,ny,nsUp,nsDown,s1,s2,evil))%mod;
        }

        return dp[x][y][sUp][sDown]=ans;
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        int m=evil.size();

        lps.assign(m,0);
        {
            for(int i=0;i<m;i++)
            {
                for(int j=i-1;j>=0;j--)
                    if(evil[j]==evil[i])
                    {
                        bool good=1;
                        for(int del=0;del<=j;del++)
                            if(evil[i-del]!=evil[j-del])
                            {
                                good=0;
                                break;
                            }
                        if(good)
                        {
                            lps[i]=j+1;
                            break;
                        }
                    }
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,0,1,1,s1,s2,evil);
    }
};