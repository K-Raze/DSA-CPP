class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        vector<string>arr;
        {
            int l=0,r=0;
            int cnt1=0;
            while(r<n)
            {
                if(s[r]=='1')
                    cnt1++;
                bool loopRun=0;
                while(cnt1>=k)
                {
                    loopRun=1;
                    if(s[l]=='1')
                        cnt1--;
                    l++;
                }
                if(loopRun)
                {
                    l--;
                    cnt1++;
                }
                if(cnt1==k)
                {
                    if(arr.empty() || r-l+1<arr.front().size())
                    {
                        arr.clear();
                        arr.push_back(s.substr(l,r-l+1));
                    }
                    else if(r-l+1==arr.front().size())
                        arr.push_back(s.substr(l,r-l+1));
                }
                r++;
            }
        }
        if(arr.empty())
            return {};
        sort(arr.begin(),arr.end());
        return arr.front();
    }
};