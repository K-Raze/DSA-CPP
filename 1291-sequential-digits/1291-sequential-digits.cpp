using ll=long long;
class Solution {
public:

    set<int>st;

    void gen(ll val)
    {
        st.insert(val);
        if(val%10==9)
            return;
        if(val*10+(val%10+1)<=1e9)
            gen(val*10+(val%10+1));
    }

    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++)
            gen(i);
        auto it=st.lower_bound(low);
        vector<int>ans;
        while(it!=st.end() && *it<=high)
        {
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};