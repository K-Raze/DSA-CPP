int dp[205][105];
int memo[205][205];
class Solution {
public:

    int findMinChangeSs(string& s,int d)
    {
        int n=s.size();

        // extract the string
        vector<string>str;

        vector<bool>vis(n,0);
        for(int i=0;i<n;i++)
            if(!vis[i])
            {
                string temp;
                int idx=i;
                while(idx<n && !vis[idx])
                {
                    temp+=s[idx];
                    vis[idx]=1;
                    idx+=d;
                }
                str.push_back(temp);
            }

        int ans=0;
        for(string& t : str)
        {   
            int l=0,r=t.size()-1;
            while(l<=r)
            {
                if(t[l]!=t[r])
                    ans++;
                l++;
                r--;
            }
        }
        return ans;
    }

    int findMinChange(int i,int j,string& meow) // to make it semi pal
    {
        if(memo[i][j]!=-1)
            return memo[i][j];

        string s;
        for(int k=i;k<=j;k++)
            s+=meow[k];
        int n=s.size();

        int ans=findMinChangeSs(s,1);
        for(int i=2;i*i<=n;i++)
            if(n%i==0)
            {
                int d1=i,d2=n/i;
                ans=min(ans,findMinChangeSs(s,d1));
                ans=min(ans,findMinChangeSs(s,d2));
            }

        return memo[i][j]=ans;
    }

    int dp[205][105];

    int solve(int x,int k,string& s)
    {
        if(x>=s.size())
            return 2e9;

        if(k==1)
        {
            if(x!=s.size()-1)
                return findMinChange(x,s.size()-1,s);
            return 2e9;
        }
        if(dp[x][k]!=-1)
            return dp[x][k];

        int ans=2e9;

        for(int i=x+1;i<s.size();i++)
            ans=min(ans,findMinChange(x,i,s)+solve(i+1,k-1,s));
        return dp[x][k]=ans;
    }

    int minimumChanges(string s, int k) {
        memset(memo,-1,sizeof(memo));
        memset(dp,-1,sizeof(dp));
        return solve(0,k,s);
    }
};