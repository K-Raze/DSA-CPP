class Solution {
public:
    int maximumPossibleSize(vector<int>& arr) {
        vector<int>st;
        for(int& x : arr)
        {
            if(!st.empty() && st.back()>x)
                continue;
            st.push_back(x);
        }
        return st.size();
    }
};