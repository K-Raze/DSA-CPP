class Solution {
public:

    int way(int x,int k,vector<int>& arr)
    {
        if(x==arr.size())
            return !k;
        return way(x+1,k+arr[x],arr)+way(x+1,k-arr[x],arr);
    }

    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        return way(0,target,arr);
    }
};