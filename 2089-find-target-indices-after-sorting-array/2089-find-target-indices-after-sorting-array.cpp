class Solution {
public:
    vector<int> targetIndices(vector<int>& arr, int target) {
        vector<int>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
            if(arr[i]==target)
                ans.push_back(i);
        return ans;
    }
};