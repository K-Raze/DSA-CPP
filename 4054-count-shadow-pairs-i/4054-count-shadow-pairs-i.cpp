using ll=long long;
class Solution {
public:

    // next smaller ke bad i cant take anything
    // diccut is dup counting , wo bhi hojega
    // 3 7 6 10

    long long shadowPairs(vector<int>& arr) {
        int n=arr.size();
        ll ans=0;

        vector<int>dupCnt(n,0);
        stack<int>st;

        for(int i=n-1;i>=0;i--)
        {
            int dc=0;
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                if(arr[st.top()]==arr[i])
                    dc+=dupCnt[st.top()]+1;
                st.pop();
            }
            int ns=n;
            if(!st.empty())
                ns=st.top();
            int gt=ns-i-1;
            gt-=dc;
            dupCnt[i]=dc;
            ans+=gt;
            st.push(i);
        }
        return ans;
    }
};