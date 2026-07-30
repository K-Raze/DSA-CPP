class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        stack<string>st;

        string dirName;
        while(getline(ss,dirName,'/'))
            if(!dirName.empty())
            {
                if(dirName==".")    
                    continue;
                else if(dirName=="..")
                {
                    if(!st.empty())
                        st.pop();
                }
                else
                {
                    reverse(dirName.begin(),dirName.end());
                    st.push(dirName);
                }
            }
        string ans;
        while(!st.empty())
        {
            string s=st.top();
            st.pop();
            ans+=s+"/";
        }
        if(ans.empty())
            ans+="/";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};