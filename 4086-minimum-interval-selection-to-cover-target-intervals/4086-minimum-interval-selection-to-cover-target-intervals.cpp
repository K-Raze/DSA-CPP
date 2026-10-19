class Solution {
public:

    // [[1,4],[1,7],[3,9],[5,10],[10,15]]
    // [[1,3],[2,5],[7,8],[10,13],[11,15],[12,13]]
    // 1,5  7,8  10,15  

    inline int giveFp(vector<vector<int>>& ai, vector<vector<int>>& ti)
    {
        int ans=0;
        for(auto& it : ai)
            ans=max(ans,it[1]);
        for(auto& it : ti)
            ans=max(ans,it[1]);
        return ans;
    }

    int minSelection(vector<vector<int>>& ai, vector<vector<int>>& ti) {
        // merge ti
        {
            sort(ti.begin(),ti.end());
            int s=ti[0][0],e=ti[0][1];
            vector<vector<int>>temp;
            for(auto& it : ti)
            {
                if(it[0]>=s && it[0]<=e)
                    e=max(e,it[1]);
                else
                {
                    temp.push_back({s,e});
                    s=it[0],e=it[1];
                }
            }
            temp.push_back({s,e});
            ti=temp;
        }

        int fp=giveFp(ai,ti);
        int ptr=0;
        vector<int>maxReach(fp+5,-1);
        for(auto& it : ai)
            maxReach[it[0]]=max(maxReach[it[0]],it[1]);
        vector<int>preMax=maxReach;
        for(int i=1;i<preMax.size();i++)
            preMax[i]=max(preMax[i],preMax[i-1]);

        int ans=0;
        int curr=-1;
        while(ptr<ti.size())
        {
            int start=ti[ptr][0], end=ti[ptr][1];
            if(end<=curr)
            {
                ptr++;
                continue;
            }
            int sf=max(start,curr);
            // can i cover this interval ? 
            int mr=preMax[sf];
            if(mr<=curr || mr<start)
                return -1;
            ans++;
            curr=mr;
        }
        return ans;
    }
};