const int mod=1e9+7;
class Solution {
public:

    int numberOfGoodPartitions(vector<int>& arr) {
        int n=arr.size();

        unordered_map<int,int>last;
        for(int i=0;i<n;i++)
            last[arr[i]]=i;
        
        int x=0;
        int ans=1;
        bool tikku=0;
        while(x!=n)
        {
            if(tikku)
                ans=(ans*2)%mod;
            else
                tikku=1;

            int end=last[arr[x]];
            for(int i=x;i<=end;i++)
                end=max(end,last[arr[i]]);
            x=end+1;
        }

        return ans;
    }
};