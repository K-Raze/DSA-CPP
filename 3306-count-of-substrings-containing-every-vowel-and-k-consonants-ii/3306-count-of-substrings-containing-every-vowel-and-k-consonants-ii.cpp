using ll=long long;
class Solution {
public:
    long long countOfSubstrings(string s, int k) {
        int n=s.size();
        vector<int>consVec;
        for(int r=0;r<n;r++)
            if(!(s[r]=='a' || s[r]=='e' || s[r]=='i' ||
                    s[r]=='o' || s[r]=='u'))
                        consVec.push_back(r);
        int l=0,r=0;

        unordered_map<char,int>cntVow;
        int vow=0;
        unordered_map<char,int>last;
        int cons=0;
        ll ans=0;
        while(r<n)
        {
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' ||
                    s[r]=='o' || s[r]=='u')
            {
                cntVow[s[r]]++;
                if(cntVow[s[r]]==1)
                    vow++;
                last[s[r]]=r;
            }
            else
                cons++;

            while(cons>k)
            {
                if(s[l]=='a' || s[l]=='e' || s[l]=='i' ||
                    s[l]=='o' || s[l]=='u')
                {
                    cntVow[s[l]]--;
                    if(cntVow[s[l]]==0)
                        vow--;
                }
                else
                    cons--;
                l++;
            }

            if(cons==k && vow==5)
            {
                int bound=n;
                bound=min(bound,last['a']);
                bound=min(bound,last['e']);
                bound=min(bound,last['i']);
                bound=min(bound,last['o']);
                bound=min(bound,last['u']);
                if(k)
                {
                    auto it=lower_bound(consVec.begin(),consVec.end(),l);
                    if(it!=consVec.end())
                        bound=min(bound,*it);
                }
                bound--;
                ans+=bound-l+2;
            }

            r++;
        }
        return ans;
    }
};