int mj[105][105][105];
class Solution {
public:

    int solve(int l,int r,int cnt,string& s,int k,vector<vector<int>>& ex)
    {
        if(cnt>=k)
            return 2e9;
        if(r==s.size()-1)
        {
            if(cnt==k-1)
                return ex[l][r];
            return 2e9;
        }

        if(mj[l][r][cnt]!=-1)
            return mj[l][r][cnt];

        // skip it
        int ans=solve(l,r+1,cnt,s,k,ex);
        // take it 
        ans=min(ans,ex[l][r]+solve(r+1,r+1,cnt+1,s,k,ex));
        return mj[l][r][cnt]=ans;
    }

    int palindromePartition(string s, int k) {
        int n=s.size();

        vector<vector<int>>ex(n,vector<int>(n,0));

        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
            {
                int l=i,r=j;
                while(l<=r)
                {
                    if(s[l]!=s[r])
                        ex[i][j]++;
                    l++;
                    r--;
                }
            }
        memset(mj,-1,sizeof(mj));
        return solve(0,0,0,s,k,ex);
    }
};