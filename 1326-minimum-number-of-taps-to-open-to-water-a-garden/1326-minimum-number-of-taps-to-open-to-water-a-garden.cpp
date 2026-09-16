class Solution {
public: 

    

    int minTaps(int n, vector<int>& ranges) {
        vector<int>maxReach(n+1);
        iota(maxReach.begin(),maxReach.end(),0);

        for(int i=0;i<=n;i++)
        {
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            maxReach[l]=max(maxReach[l],r);
        }
        int pos=0;
        int reach=0;
        int ans=0;
        while(pos<=n && pos<=reach)
        {
            int nreach=reach;
            for(int i=pos;i<=reach;i++)
                nreach=max(nreach,maxReach[i]);
            ans++;
            pos=reach+1;
            reach=nreach;
        }
        if(reach<n)
            return -1;
        return ans-1;
    }
};