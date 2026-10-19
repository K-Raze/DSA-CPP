class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        map<int,int>diff;
        {
            for(auto& it : flowers)
            {
                diff[it[0]]++;
                diff[it[1]+1]--;
            }
            auto it=diff.begin();
            it++;
            auto pit=diff.begin();
            while(it!=diff.end())
            {
                it->second+=pit->second;
                it++;
                pit++;
            }
        }
        vector<int>ans;
        for(int& pos : people)
        {
            auto it=diff.upper_bound(pos);
            if(it==diff.begin())
                ans.push_back(0);
            else
            {
                it--;
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};