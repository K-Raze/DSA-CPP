class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& arr) {
        map<pair<int,int>,int>cnt;

        for(int i=1;i<arr.size();i++)
        {
            int l=arr[i-1],r=arr[i];
            if(r>l)
                swap(r,l);
            cnt[{l,r}]++;
        }
        int ans=0;
        int tep=0;
        for(auto&[a,b] : cnt)
        {
            auto&[l,r]=a;
            if(l==r)
                tep+=b;
        }
        
        ans=max(ans,tep);

        for(auto&[a,b] : cnt)
        {
            auto&[l,r]=a;
            if(l!=r)
                ans=max(ans,b+tep);
        }
        return ans;
    }
};