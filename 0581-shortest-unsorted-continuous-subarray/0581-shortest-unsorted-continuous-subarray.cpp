class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>arr=nums;
        sort(arr.begin(),arr.end());
        int l=arr.size(),r=-1;
        int n=arr.size();
        for(int i=0;i<n;i++)
            if(arr[i]!=nums[i])
            {
                l=i;
                break;
            }
        for(int i=n-1;i>=0;i--)
            if(arr[i]!=nums[i])
            {
                r=i;
                break;
            }
        if(l>r)
            return 0;
        return r-l+1;
    }
};