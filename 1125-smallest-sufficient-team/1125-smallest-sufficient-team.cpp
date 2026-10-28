// 60 * (1<<16)
// 60*64 * 1000

int dp[63][1<<16];

class Solution {
public:

    int solve(int x,int mask,vector<int>& skillMask,int n)
    {
        if(x==skillMask.size())
        {
            if(mask==((1<<n)-1))
                return 0;
            return 2e9;
        }
        if(dp[x][mask]!=-1)
            return dp[x][mask];
        // skip
        int ans=solve(x+1,mask,skillMask,n);
        // take
        ans=min(ans,1+solve(x+1,mask | skillMask[x],skillMask,n));
        return dp[x][mask]=ans;
    }

    void track(int x,int mask,vector<int>& skillMask,int n,vector<int>& vec)
    {
        if(x==skillMask.size())
            return;
        // skip
        int skip=solve(x+1,mask,skillMask,n);
        // take
        int take=1+solve(x+1,mask | skillMask[x],skillMask,n);
        if(take<skip)
        {
            vec.push_back(x);
            track(x+1,mask | skillMask[x],skillMask,n,vec);
        }
        else
            track(x+1,mask,skillMask,n,vec);
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people_skills) {
        // simlify it 
        int n=req_skills.size();
        int m=people_skills.size();
        vector<int>skillMask(people_skills.size());
        {
            unordered_map<string,int>mp;
            {
                int idx=0;
                for(string& s : req_skills)
                    mp[s]=idx++;
            }

            for(int i=0;i<m;i++)
            {
                int mask=0;
                for(string& s : people_skills[i])
                {
                    int idx=mp[s];
                    mask|=(1<<idx);
                }
                skillMask[i]=mask;
            }
        }
        memset(dp,-1,sizeof(dp));
        solve(0,0,skillMask,n);

        // track kr
        vector<int>ans;
        track(0,0,skillMask,n,ans);
        return ans;
    }
};