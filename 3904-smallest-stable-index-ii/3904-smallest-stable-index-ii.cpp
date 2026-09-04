class Solution {
public:
    int firstStableIndex(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>minSuff(n);
        minSuff[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
            minSuff[i]=min(minSuff[i+1],arr[i]);
        int maxi=-2e9;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]);
            if(maxi-minSuff[i]<=k)
                return i;
        }
        return -1;
    }
};