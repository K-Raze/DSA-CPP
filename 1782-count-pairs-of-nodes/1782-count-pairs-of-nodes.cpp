class Solution {
public:

    // da+db > q
    // da+db-1 > q  

    // da+db > q
    // da+db-se <=q 

    // 2 3 6 9 13
    // q
    // ia+ib>q
    // 2+ib>q
    // ib>q-2
    // -1 
    // 2,4,7
    // q=6
    // 4>
    // 2>

    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        map<pair<int,int>,int>cEdge;
        vector<int>degree(n,0);
        for(auto& it : edges)
        {
            it[0]--;
            it[1]--;
            if(it[1]<it[0])
                swap(it[0],it[1]);
            cEdge[{it[0],it[1]}]++;
            degree[it[0]]++;
            degree[it[1]]++;
        }
        vector<int>oDeg=degree;
        sort(degree.begin(),degree.end());
        vector<int>ans;
        for(int& q : queries)
        {
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                int ia=degree[i];
                int idx=upper_bound(degree.begin()+i+1,degree.end(),q-ia)-degree.begin();
                cnt+=n-idx;
            }
            ans.push_back(cnt);
        }

        for(int i=0;i<queries.size();i++)
        {
            int q=queries[i];
            for(auto&[p,ce] : cEdge)
            {
                auto[u,v]=p;
                if(oDeg[u]+oDeg[v]-ce<=q && oDeg[u]+oDeg[v]>q)
                    ans[i]--;
            }
        }
        return ans;
    }
};