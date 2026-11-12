class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int n=arr.size();
        int ans=1;

        for(int i=0;i<arr.size();i++)
        {
            int inc=1,dec=1;
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[j]>arr[j-1])
                    inc++;
                else
                    break;
            }
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[j]<arr[j-1])
                    dec++;
                else
                    break;
            }
            ans=max(ans,max(inc,dec));
        }
        return ans;
    }
};