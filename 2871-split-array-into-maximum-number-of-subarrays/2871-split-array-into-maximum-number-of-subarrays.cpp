class Solution {
public:
    int maxSubarrays(vector<int>& arr) {
        int n=arr.size();

        int totalAnd=-1;
        for(int& x : arr)
            totalAnd&=x;

        if(!totalAnd)
        {
            int ans=0;
            int currAnd=-1;
            for(int& x : arr)
            {
                currAnd&=x;
                if(currAnd==totalAnd)
                {
                    ans++;
                    currAnd=-1;
                }
            }
            return ans;
        }
        return 1;
    }
};