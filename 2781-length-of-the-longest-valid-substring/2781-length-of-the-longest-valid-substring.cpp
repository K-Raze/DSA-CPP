class Solution {
public:
    int longestValidSubstring(string s, vector<string>& forbidden) {
        unordered_set<string>fb;
        for(string& s : forbidden)
            fb.insert(s);

        int n=s.size();

        int l=0,r=0;
        int ans=0;
        while(r<n)
        {
            int idx=-1;
            for(int i=r;i>=max(l,r-9);i--)
                if(fb.find(s.substr(i,r-i+1))!=fb.end())
                {
                    idx=i+1;
                    break;
                }
            r++;
            if(idx!=-1)
                l=idx;
            ans=max(ans,r-l);
            // cout<<l+1<<" "<<r<<endl;
        }
        return ans;
    }
};