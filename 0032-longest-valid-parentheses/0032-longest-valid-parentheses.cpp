class Solution {
public:

    // )()())
    // -1 0 -1 0 -1 -2

    // (()
    // 1 2 1

    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int>pre(n);
        for(int i=0;i<n;i++)
            pre[i]=(s[i]=='(') ? 1 : -1;
        for(int i=1;i<n;i++)
            pre[i]+=pre[i-1];
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
            mp[pre[i]].push_back(i);

        int ans=0;
        for(int i=0;i<n;i++)
            if(s[i]=='(')
            {
                if(mp[pre[i]-1].empty())
                    continue;
                int end;
                {
                    auto& vec=mp[pre[i]-2];
                    auto it=upper_bound(vec.begin(),vec.end(),i);
                    if(it==vec.end())
                        end=n;
                    else
                        end=*it;
                }
                auto& vec=mp[pre[i]-1];
                auto it=lower_bound(vec.begin(),vec.end(),end);
                if(it==vec.begin())
                    continue;
                it--;
                if(*it<=i)
                    continue;
                ans=max(ans,*it-i+1);
            }
        return ans;
    }
};