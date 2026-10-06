class Solution {
public:
    int maxSubarray(vector<int>& arr) {
        int n=arr.size();

        int maxVal=*max_element(arr.begin(),arr.end());
        vector<int>cnt(maxVal+1,0);

        int ans=0;

        int l=0;
        for(int r=0;r<n;r++)
        {
            // check if problem
            for(int val=1;val<=maxVal;val++)
                while(cnt[val] && val+arr[r]<=maxVal && cnt[val+arr[r]])
                {
                    cnt[arr[l]]--;
                    l++;
                }
            for(int val=1;val<arr[r];val++)
                while(cnt[val] &&
                (  (2*val==arr[r] && cnt[val]>=2) || (2*val!=arr[r] && cnt[arr[r]-val]) )
                )
                {
                    cnt[arr[l]]--;
                    l++;
                }
            cnt[arr[r]]++;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};