class Solution {
public:
    int sortPermutation(vector<int>& arr) {
        int ans=INT_MAX;
        for(int i=0;i<arr.size();i++)
            if(i!=arr[i])
                ans&=i;
        return (ans!=INT_MAX) ? ans : 0;
    } 
};