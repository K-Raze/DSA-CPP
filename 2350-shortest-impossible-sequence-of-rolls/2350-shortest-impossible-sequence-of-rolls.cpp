class Solution {
public:
    int shortestSequence(vector<int>& arr, int k) {
        int ans=1;
        int diff=k;

        vector<int>cnt(k+1,0);
        for(int i=arr.size()-1;i>=0;i--)
        {
            int val=arr[i];
            if(cnt[val]<ans)
            {
                cnt[val]++;
                diff--;
            }
            if(!diff)
            {
                diff=k;
                ans++;
            }
        }
        return ans;
    }
};