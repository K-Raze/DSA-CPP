class Solution {
public:

    vector<int>rIdx;
    string ans;
    void print(int l,vector<int>rIdx,string& s)
    {
        if(l==s.size())
            return;
        int r=rIdx[l];
        for(int i=l+1;i<r;i++)
            ans+=s[i];
        print(r+1,rIdx,s);
    }

    string removeOuterParentheses(string s) {
        int n=s.size();
        rIdx.assign(n,-1);
        {
            vector<int>st;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='(')
                    st.push_back(i);
                else
                {
                    rIdx[st.back()]=i;
                    st.pop_back();
                }
            }
        }
        print(0,rIdx,s);
        return ans;
    }
};