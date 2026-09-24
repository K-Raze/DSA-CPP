class Solution {
public:



    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char,unordered_set<char>>mp;
        for(auto& it : mappings)
        {
            char ch1=it[0],ch2=it[1];
            mp[ch1].insert(ch2);
        }

        for(int i=0;i<=s.size()-sub.size();i++)
        {
            bool good=1;
            for(int j=0;j<sub.size();j++)
            {
                char c1=s[i+j],c2=sub[j];
                auto& st=mp[c2];
                if(!(c1==c2 || st.find(c1)!=st.end()))
                {
                    good=0;
                    break;
                }
            }
            if(good)
                return 1;
        }
        return 0;
    }
};