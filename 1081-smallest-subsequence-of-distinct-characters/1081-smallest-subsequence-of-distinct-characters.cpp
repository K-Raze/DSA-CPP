class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int>lastInd(26);
        vector<bool>inSt(26,0);

        for(int i=0;i<n;i++)
            lastInd[s[i]-'a']=i;

        stack<int>st;

        for(int i=0;i<n;i++)
        {
            if(inSt[s[i]-'a'])
                continue;

            while(!st.empty() && s[i]<s[st.top()] && lastInd[s[st.top()]-'a']>i)
            {
                inSt[s[st.top()]-'a']=0;
                st.pop();
            }
            inSt[s[i]-'a']=1;
            st.push(i);
        }

        string ans;
        while(!st.empty())
        {
            ans+=s[st.top()];
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};