using ll=long long;
class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        ll ans=0;

        for(int i=0;i<n;i++)
        {
            int l=arr[i][0];
            int r=arr[i][1];
            ans+=upper_bound(arr.begin(),arr.end(),vector<int>{r+1,-1})-arr.begin()-i-1;
        }
        return ans;
    }
};