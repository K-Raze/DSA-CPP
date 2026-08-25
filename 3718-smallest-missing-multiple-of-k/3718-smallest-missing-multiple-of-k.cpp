class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>arr;
        for(int n: nums)
            if(n%k==0)
                arr.insert(n);
        int a=k;
        for(int x : arr)
        {
            if(k!=x)
                return k;
            k+=a;
        }
        return k;
    }
};