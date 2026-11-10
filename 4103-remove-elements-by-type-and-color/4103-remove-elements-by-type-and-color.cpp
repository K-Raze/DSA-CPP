class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        stack<array<int,3>>st; // cnt , type,color

        for(int i=0;i<types.size();i++)
        {
            int t=types[i],c=colors[i];
            if(st.empty())
                st.push({1,t,c});
            else
            {
                auto meow=st.top();
                if(meow[1]==t && meow[2]==c)
                {
                    st.pop();
                    meow[0]++;
                    st.push(meow);
                }
                else
                    st.push({1,t,c});
            }

            // check
            if(st.empty())
                continue;
            auto meow=st.top();
            if(groupSize[meow[1]]==meow[0])
                st.pop();
        }
        return st.empty();
    }
};