class Solution {
public:

    // baaca
    // abaca

    string orderlyQueue(string s, int z) {
        if(z>1)
        {
            sort(s.begin(),s.end());
            return s;
        }

        int l=0,r=1,k=0;
        int n=s.size();
        s+=s;
        while(l<n && r<n && k<n)
        {
            if(s[l+k]==s[r+k])
                k++;
            else
            {
                if(s[l+k]<s[r+k])
                    r+=k+1;
                else
                    l+=k+1;
                if(l==r)
                    r++;
                k=0;
            }
        }
        l=min(l,r);
        return s.substr(l,n);
    }
};