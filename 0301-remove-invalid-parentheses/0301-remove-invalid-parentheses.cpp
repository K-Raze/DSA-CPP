class Solution {
public:

    set<string>ans;

    void generate(int x,int bal,int rem,string& temp,string& s)
    {
        if(bal<0 || rem<0)   
            return;
        if(x==s.size())
        {
            if(!bal)
                ans.insert(temp);
            return;
        }
        // if char
        if(s[x]!='(' && s[x]!=')')
        {
            temp+=s[x];
            generate(x+1,bal,rem,temp,s);
            temp.pop_back();
        }
        else if(s[x]=='(')
        {
            // take
            temp+=s[x];
            generate(x+1,bal+1,rem,temp,s);
            temp.pop_back();
            // not take
            generate(x+1,bal,rem-1,temp,s);
        }
        else if(s[x]==')')
        {
            // take
            temp+=s[x];
            generate(x+1,bal-1,rem,temp,s);
            temp.pop_back();
            // not take
            generate(x+1,bal,rem-1,temp,s);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
        int minRemNeed=0;
        {
            string st;
            for(char& ch : s)
            {
                if(ch!='(' && ch!=')')
                    continue;
                if(ch=='(')
                    st+=ch;
                else 
                {
                    if(!st.empty())
                        st.pop_back();
                    else
                        minRemNeed++;
                }
            }
            minRemNeed+=st.size();
        }
        string temp;
        generate(0,0,minRemNeed,temp,s);
        vector<string>res(ans.begin(),ans.end());
        return res;
    }
};