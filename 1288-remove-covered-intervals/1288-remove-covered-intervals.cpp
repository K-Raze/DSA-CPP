class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),[&](const auto& a,const auto& b)
        {
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int ans=0;
        int r=-1;
        for(auto& it : arr)
            if(it[1]>r)
            {
                ans++;
                r=it[1];
            }
        return ans;
    }
};