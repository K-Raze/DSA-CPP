using ll=long long;
const int mod=1e9+7;
class Solution {
public:

    vector<vector<ll>>matrixMul(const vector<vector<ll>>& a,const vector<vector<ll>>& b)
    {
        int nr=a.size(),nc=b[0].size();
        vector<vector<ll>>ans(nr,vector<ll>(nc));

        for(int r=0;r<a.size();r++)
            for(int c=0;c<b[0].size();c++)
            {
                ans[r][c]=0;
                for(int k=0;k<a[0].size();k++)
                    ans[r][c]=(ans[r][c]+1LL*a[r][k]*b[k][c])%mod;
            }
        return ans;
    }   

    vector<vector<ll>> I={
        {1,0},
        {0,1}
    };

    vector<vector<ll>>matrixExpo(const vector<vector<ll>>& a,ll p)
    {
        if(p==0)
            return I;
        vector<vector<ll>> ans=matrixExpo(a,p/2);
        ans=matrixMul(ans,ans);
        if(p&1)
            ans=matrixMul(ans,a);
        return ans;
    }

    int countGoodStrings(long long n) {
        vector<vector<ll>> M={
            {1},
            {0}
        };
        if(n&1)
            M={
                {1},
                {1}
            };
        
        n>>=1;

        vector<vector<ll>>MM={
            {2,1},
            {1,1}
        };
        vector<vector<ll>>ans=matrixExpo(MM,n);
        ans=matrixMul(ans,M);
        return (2LL*ans[1][0])%mod; 
    }
};