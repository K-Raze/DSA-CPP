class Solution {
public:

    // 1 3
    // \ /
    //  2

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // find rc
        vector<int>rowNum(k+1);
        {
            vector<int>inDegree(k+1,0);
            vector<vector<int>>adj(k+1);
            for(auto& it : rowConditions)
            {
                inDegree[it[1]]++;
                adj[it[0]].push_back(it[1]);
            }

            int r=0;
            queue<int>q;
            for(int i=1;i<=k;i++)
                if(!inDegree[i])
                    q.push(i);
            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                rowNum[x]=r++;
                for(int& y : adj[x])
                {
                    inDegree[y]--;
                    if(!inDegree[y])
                        q.push(y);
                }
            }
            if(r!=k)
                return {};
        }
        // find cc
        vector<int>colNum(k+1);
        {
            vector<int>inDegree(k+1,0);
            vector<vector<int>>adj(k+1);
            for(auto& it : colConditions)
            {
                inDegree[it[1]]++;
                adj[it[0]].push_back(it[1]);
            }

            int c=0;
            queue<int>q;
            for(int i=1;i<=k;i++)
                if(!inDegree[i])
                    q.push(i);
            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                colNum[x]=c++;
                for(int& y : adj[x])
                {
                    inDegree[y]--;
                    if(!inDegree[y])
                        q.push(y);
                }
            }
            if(c!=k)
                return {};
        } 
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++)
            ans[rowNum[i]][colNum[i]]=i;
        return ans;
    }
};