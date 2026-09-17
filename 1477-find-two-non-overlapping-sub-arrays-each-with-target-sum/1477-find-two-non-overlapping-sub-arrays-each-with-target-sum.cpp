class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int tar) {
        int n=arr.size();
        unordered_map<int,int>sumIdx;
        vector<int>minLen(n,2e9);
        {
            sumIdx[0]=n;
            int sum=0;
            for(int i=n-1;i>=0;i--)
            {
                sum+=arr[i];
                // sum-suff==tar
                // sum-tar
                if(sumIdx.find(sum-tar)!=sumIdx.end())
                    minLen[i]=sumIdx[sum-tar]-i;
                sumIdx[sum]=i;
            }
        }
        // for(int i=0;i<n;i++)
        //     cout<<minLen[i]<<" ";
        vector<int>suffMin=minLen;
        for(int i=n-2;i>=0;i--)
            suffMin[i]=min(suffMin[i],suffMin[i+1]);
        int ans=2e9;
        for(int i=0;i<n-1;i++)
            if(minLen[i]!=2e9 && i+minLen[i]<n && suffMin[i+minLen[i]]!=2e9)
                ans=min(ans,suffMin[i+minLen[i]]+minLen[i]);
        if(ans==2e9)
            return -1;
        return ans;
    }
};