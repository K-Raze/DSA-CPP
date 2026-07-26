class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        set<int>st;
        for(auto& it : series1)
            st.insert(it[0]);
        for(auto& it : series2)
            st.insert(it[0]);
        vector<vector<int>>ans;
        for(int val : st)
        {
            int sum=0;
            {
                auto it=lower_bound(series1.begin(),series1.end(),vector<int>{val,-1});
                if(it!=series1.end())
                    sum+=(*it)[1];
            }
            {
                auto it=lower_bound(series2.begin(),series2.end(),vector<int>{val,-1});
                if(it!=series2.end())
                    sum+=(*it)[1];
            }
            ans.push_back({val,sum});
        }
        return ans;
    }
};