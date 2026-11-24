class Solution {
public:
    int countOfSubstrings(string s, int k) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            set<char>vow;
            int cons=0;
            for(int j=i;j<n;j++)
            {
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' ||
                    s[j]=='o' || s[j]=='u')
                        vow.insert(s[j]);
                else
                    cons++;
                if(vow.size()==5 && cons==k)
                    ans++;
            }
        }
        return ans;
    }
};