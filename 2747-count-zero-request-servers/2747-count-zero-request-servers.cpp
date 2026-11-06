class Solution {
public:

    // sliding window ? 

    vector<int> countServers(int n, vector<vector<int>>& log, int x, vector<int>& queries) {
        sort(log.begin(),log.end(),[&](const auto& a,const auto& b){
            return a[1]<b[1];
        });

        vector<array<int,3>>interval;
        for(int i=0;i<queries.size();i++)
            interval.push_back({queries[i]-x,
                queries[i],i});
        sort(interval.begin(),interval.end());

        int l=0,r=0;
        int diff=0;
        unordered_map<int,int>cnt;

        vector<int>ans(queries.size());

        for(auto&[left,right,idx] : interval)
        {
            while(l<log.size() && log[l][1]<left) // remove krna h ye sb
            {
                int id=log[l][0];
                cnt[id]--;
                if(!cnt[id])
                    diff--;
                l++;
            }
            while(r<log.size() && log[r][1]<=right) // add krna h ye sb
            {
                int id=log[r][0];
                cnt[id]++;
                if(cnt[id]==1)
                    diff++;
                r++;
            }
            ans[idx]=n-diff;
        }
        return ans;
    }
};