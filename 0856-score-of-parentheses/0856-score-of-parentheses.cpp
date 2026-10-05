int dp[52];
class Solution {
public:

    vector<int>balIdx;

    int solve(int l,string& s)
    {
        if(l>=balIdx.size())
            return 0;
        if(dp[l]!=-1)
            return dp[l];
        int r=balIdx[l];
        int next=0;
        if(r+1<balIdx.size() && s[r+1]=='(')
            next=solve(r+1,s);
        if(l+1==r)
            return dp[l]=1+next;
        return dp[l]=2*solve(l+1,s)+next;
    }

    int scoreOfParentheses(string s) {
        int n=s.size();
        balIdx.resize(n,-1);
        {
            stack<int>st;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='(')
                    st.push(i);
                else
                {
                    balIdx[st.top()]=i;
                    st.pop();
                }
            }
            // for(int i=0;i<n;i++)
            //     cout<<balIdx[i]<<" ";
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};