class Solution {
public:

    // sare rotation check krle

    int minOperations(string s) {
        int n=s.size();
        int ans=2e9;
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int i=0;i<n/2;i++)
            {
                char ch1=s[i];
                char ch2=s[n-i-1];
                temp+=min((ch2-ch1+26)%26,(ch1-ch2+26)%26);
            }
            ans=min(ans,temp+i);
            char last=s.front();
            for(int i=0;i<n-1;i++)
                s[i]=s[i+1];
            s[n-1]=last;
        }
        return ans;
    }
};