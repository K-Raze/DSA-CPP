// 1 1 2 3 3 4 
int dp[100005][2];
class Solution {
public:

    int solve(int x,bool inc,vector<pair<int,int>>& temp)
    {
        if(x==temp.size()-1)
        {
            int ans=1;
            if(!inc && temp[x].second>1)
                ans=2;
            return ans;
        }
        
        if(dp[x][inc]!=-1)
            return dp[x][inc];

        // normal go
        int ans=1;

        if(!inc)
        {
            if(temp[x].second>1)
                ans=2;

            if(temp[x+1].first==temp[x].first+1)
                ans=max(ans,1+solve(x+1,inc,temp));
            
            if(temp[x].second>1 && temp[x+1].first==temp[x].first+2)
                ans=max(ans,2+solve(x+1,inc,temp));

            if(temp[x].second>1 && temp[x+1].first==temp[x].first+1)
                ans=max(ans,2+solve(x+1,1,temp));
        }
        else
        {
            if(temp[x+1].first==temp[x].first+1)
                ans=max(ans,1+solve(x+1,inc,temp));
            if(temp[x+1].first==temp[x].first+2)
                ans=max(ans,1+solve(x+1,0,temp));
        }
        return dp[x][inc]=ans;
    }

    int maxSelectedElements(vector<int>& arr) {
        map<int,int>cnt;
        for(int& x : arr)
            cnt[x]++;
        vector<pair<int,int>>temp;
        for(auto& [a,b] : cnt)
        {
            // cout<<a<<" "<<b<<endl;
            temp.push_back({a,b});
        }
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<temp.size();i++)
        {
            ans=max(ans,solve(i,0,temp));
            ans=max(ans,solve(i,1,temp));
        }
        return ans;
    }
};