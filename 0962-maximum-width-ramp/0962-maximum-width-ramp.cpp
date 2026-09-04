class Solution {
public:

    inline bool check(int k,vector<int>& arr)
    {
        int r=INT_MIN;
        for(int i=arr.size()-k-1;i>=0;i--)
        {
            r=max(r,arr[i+k]);
            if(r>=arr[i])
                return 1;
        }
        return 0;
    }

    int maxWidthRamp(vector<int>& arr) {
        int start=0,end=arr.size();
        while(start<=end)
        {
            int mid=start+((end-start)>>1);
            if(check(mid,arr))
                start=mid+1;
            else
                end=mid-1;
        }
        return end;
    }
};