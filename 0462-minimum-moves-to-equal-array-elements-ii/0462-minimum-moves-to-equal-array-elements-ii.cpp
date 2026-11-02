class Solution {
public:
    int minMoves2(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int med=arr[arr.size()/2];
        if(!(arr.size()&1))
        {
            med+=arr[arr.size()/2-1];
            med/=2;
        }
        int ans=0;
        for(int& x : arr)
            ans+=abs(med-x);
        return ans;
    }
};