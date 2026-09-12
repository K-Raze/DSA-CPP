using ll=long long;
using node=pair<ll,array<int,4>>;
node dp[50005][5];
bool vis[50005][5];
class Solution {
public:

    // umm i can track the dp but lexo thing how 

    bool checkLexo(const auto& a,const auto& b)
    {
        vector<int> ta,tb;

        for(int x : a)
            if(x!=-1)
                ta.push_back(x);

        for(int x : b)
            if(x!=-1)
                tb.push_back(x);

        sort(ta.begin(),ta.end());
        sort(tb.begin(),tb.end());

        for(int i=0;i<ta.size();i++)
        {
            if(ta[i] < tb[i])
                return 0;
            if(tb[i] < ta[i])
                return 1;
        }

        if(ta.size()<tb.size())
            return 0;
        return 1;
    }

    inline void fit(array<int,4>&vec,int idx)
    {
        for(int i=0;i<4;i++)    
            if(vec[i]==-1)
            {
                vec[i]=idx;
                return;
            }
    }

    node solve(int x,int y,vector<vector<int>>& arr)
    {
        array<int,4> idxVec = {-1, -1, -1, -1};
        if(y==4 || x==arr.size())
            return {0,idxVec};

        if(vis[x][y])
            return dp[x][y];
        vis[x][y]=1;
        // skip 
        auto temp1=solve(x+1,y,arr);
        // take
        int idx=lower_bound(arr.begin(),arr.end(),vector<int>{arr[x][1]+1,-1,-1,-1})-arr.begin();
        auto temp2=solve(idx,y+1,arr);
        temp2.first+=arr[x][2];
        fit(temp2.second,arr[x][3]);

        // return
        if(temp1.first<temp2.first)
            return dp[x][y]=temp2;
        else if(temp2.first<temp1.first)
            return dp[x][y]=temp1;
        if(checkLexo(temp1.second,temp2.second))
            return dp[x][y]=temp2;
        return dp[x][y]=temp1;
    }

    vector<int> maximumWeight(vector<vector<int>>& arr) {
        for(int i=0;i<arr.size();i++)
            arr[i].push_back(i);
        sort(arr.begin(),arr.end());

        memset(vis,0,sizeof(vis));
        auto[sum,vec]=solve(0,0,arr);
        vector<int>ta;
        for(int x : vec)
            if(x!=-1)
                ta.push_back(x);
        sort(ta.begin(),ta.end());
        return ta;
    }
};