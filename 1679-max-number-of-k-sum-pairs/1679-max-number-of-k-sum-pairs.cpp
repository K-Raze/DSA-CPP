class Solution {
public:
    int maxOperations(vector<int>& arr, int k) {
        set<int>st(arr.begin(),arr.end());
        unordered_map<int,int>cnt;
        for(int& x : arr)
            cnt[x]++;
        
        int ans=0;
        for(int x : st)
        {
            if(2*x>k)
                break;
            if(k%2==0 && x==k/2)
            {
                ans+=cnt[x]/2;
                break;
            }
            ans+=min(cnt[x],cnt[k-x]);
        }
        return ans;
    }
};