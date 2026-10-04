class Solution {
public:

    inline int minCost(int l,int r)
    {
        if(l>r)
            swap(l,r);
        int way1=r-l;
        int way2=l+1+9-r;
        return min(way1,way2);
    }

    int minRotations(int n, string s) {

        int ans=0;
        vector<int>suff(n+1,0);
        {
            for(int i=n-2;i>=0;i--)
            {
                ans+=minCost(s[i]-'0',s[i+1]-'0');
                suff[i]=ans;
            }
        }
        ans+=minCost(s.back()-'0',0);

        int curr=minCost(s.front()-'0',0);
        if(n>1)
            ans=min(ans,curr+minCost(s[0]-'0',s.back()-'0')+suff[1]);
        for(int i=1;i<n;i++)
        {
            curr+=minCost(s[i]-'0',s[i-1]-'0');
            ans=min(ans,curr+minCost(s[i]-'0',s.back()-'0')+suff[i+1]);
        }
        // cout<<curr<<endl;
        return min(ans,curr);
    }
};