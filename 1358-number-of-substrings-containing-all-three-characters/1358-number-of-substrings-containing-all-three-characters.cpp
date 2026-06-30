class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int>index(3,-1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            index[s[i]-'a']=i;
            int l=min(index[(s[i]-'a'-1+3)%3],
                index[(s[i]-'a'+1)%3]);
            if(l!=-1)
                ans+=l+1;
        }   
        return ans;
    }
};