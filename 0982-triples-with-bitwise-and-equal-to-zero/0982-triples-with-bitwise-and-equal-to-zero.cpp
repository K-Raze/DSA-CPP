int cnt[1<<16];
class Solution {
public:

    // total a&b == 2^16
    // store them
    // 2^16 and iterate on all arr 
    // 2^16 * 1e3
    // 64*1e6

    int countTriplets(vector<int>& arr) {
        memset(cnt,0,sizeof(cnt));

        int n=arr.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cnt[arr[i] & arr[j]]++;
        
        int ans=0;
        for(int u=0;u<(1<<16);u++)
            for(int& v : arr)
                if(!(u&v))
                    ans+=cnt[u];
        return ans;
    }
};