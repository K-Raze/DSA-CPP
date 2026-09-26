class Solution {
public: 
    unordered_map<string,string>mp;
    string parseKey(int& idx,string& s)
    {
        idx++;
        string temp;
        while(s[idx]!=')')
            temp+=s[idx++];
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        return "?";
    }

    string evaluate(string s, vector<vector<string>>& knowledge) {
        mp.clear();
        for(auto& it : knowledge)
            mp[it[0]]=it[1];
        
        string ans;
        int idx=0;
        while(idx<s.size())
        {
            if(s[idx]=='(')
                ans+=parseKey(idx,s);
            else
                ans+=s[idx];
            idx++;
        }
        return ans;
    }
};