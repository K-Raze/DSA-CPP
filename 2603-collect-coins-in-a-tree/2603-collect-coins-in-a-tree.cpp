class Solution {
public:

    // clear faltu ke 0 wale nodes
    // now its guranteed that leaf/end are 1 wale
    // push that node which have 1 and degree 1
    // do topo opeartion 2 time,
    // cnt rkh kitey remove hua h , ans will be (total-rem-1)*2

    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) 
    {
        int n=coins.size();
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        for(auto& it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        
        int rem=n;
        // faltu 0 node remove kr
        {
            queue<int>q;
            for(int i=0;i<n;i++)
                if(degree[i]==1 && !coins[i])
                {
                    degree[i]--;
                    q.push(i);
                }
            while(!q.empty())
            {
                rem--;
                int x=q.front();
                q.pop();
                for(int& y : adj[x])
                {
                    degree[y]--;
                    if(degree[y]==1 && !coins[y])
                        q.push(y);
                }
            }
        }
        // 1 wale dal
        {
            queue<int>q;
            for(int i=0;i<n;i++)
                if(degree[i]==1 && coins[i])
                {
                    degree[i]--;
                    q.push(i);
                }
            int cnt=0;
            while(!q.empty() && cnt<2)
            {
                cnt++;
                int sz=q.size();
                while(sz--)
                {
                    rem--;
                    int x=q.front();
                    q.pop();
                    for(int& y : adj[x])
                    {
                        degree[y]--;
                        if(degree[y]==1)
                            q.push(y);
                    }
                }
            }
        }
        rem--;
        return max(0,rem*2);
    }
};