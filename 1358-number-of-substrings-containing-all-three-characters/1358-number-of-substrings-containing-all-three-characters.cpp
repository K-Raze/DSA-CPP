class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();

        vector<vector<int>>index(3);
        for(int i=0;i<n;i++)
            index[s[i]-'a'].push_back(i);

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int r=i;
            for(int j=0;j<3;j++)
                if(j!=s[i]-'a')
                {
                    auto& vec=index[j];
                    auto it=upper_bound(vec.begin(),vec.end(),i);
                    if(it==vec.end())
                        return ans;
                    r=max(r,*it);
                }
            ans+=n-r;
        }
        return ans;
    }
};