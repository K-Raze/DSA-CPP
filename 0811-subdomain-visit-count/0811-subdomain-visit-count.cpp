class Solution {
public:

    pair<int,vector<string>> parser(string& s)
    {
        string temp;
        vector<string>domain;

        int i=0;

        while(s[i]!= ' ')
        {
            temp+=s[i];
            i++;
        }
        int count=stoi(temp);

        i++;
        temp.clear();
        while(i<s.size())
        {
            if(s[i]!='.')
                temp+=s[i];
            else
            {
                domain.push_back(temp);
                temp.clear();
            }
            i++;
        }
        domain.push_back(temp);
        return {count,domain};
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>countDomain;

        for(string& domain : cpdomains)
        {
            auto [count,vec]=parser(domain);
            for(int i=0;i<vec.size();i++)
            {
                string temp;
                for(int j=i;j<vec.size();j++)
                    temp+=vec[j]+'.';
                temp.pop_back();
                countDomain[temp]+=count;
            }
        }

        vector<string>ans;
        for(auto& [s,cnt] : countDomain)
            ans.push_back(to_string(cnt)+" "+s);
        return ans;
    }
};