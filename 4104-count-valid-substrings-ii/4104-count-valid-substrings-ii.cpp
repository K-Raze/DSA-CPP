// ezzz
using ll=long long;
class Solution {
public:
    long long countValidSubstrings(string s) {
        vector<int>a,b,c;
        ll ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
                a.push_back(i);
            else if(s[i]=='b')
                b.push_back(i);
            else if(s[i]=='c')
                c.push_back(i);

            
            // c
            int idx=-1;
            {
                auto it=upper_bound(c.begin(),c.end(),i);
                if(it!=c.begin())
                {
                    it--;
                    idx=*it;
                }
                else 
                    idx=-1;
            }
            // b
            {
                auto it=upper_bound(b.begin(),b.end(),idx);
                if(it!=b.begin())
                {
                    it--;
                    idx=*it;
                }
                else
                    idx=-1;
            }
            // a
            {
                auto it=upper_bound(a.begin(),a.end(),idx);
                if(it!=a.begin())
                {
                    it--;
                    idx=*it;
                }
                else
                    idx=-1;
            }
            ans+=i-idx;
        }
        return ans;
    }
};