class Solution {
public:
    int maxSubarrayLength(vector<int>& arr, int k) {
        unordered_map<int,int>count;
        int ans=INT_MIN;
        int first=0,second=0;
        while(second<arr.size())
        {
            count[arr[second]]++;
            while(count[arr[second]]>k)
                count[arr[first++]]--;
            ans=max(ans,second-first+1);
            second++;
        }
        return ans;
    }
};