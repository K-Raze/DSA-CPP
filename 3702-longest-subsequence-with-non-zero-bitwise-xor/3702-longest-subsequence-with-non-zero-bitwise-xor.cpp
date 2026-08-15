class Solution {
public:
    int longestSubsequence(vector<int>& arr) {
        bool all0=1;
        int xr=0;
        for(int num : arr)
        {
            if(num)
                all0=0;
            xr^=num;
        }
        if(all0)
            return 0;
        if(xr)
            return arr.size();
        return arr.size()-1;
        
    }
};