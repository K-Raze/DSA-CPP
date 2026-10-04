const int mod=1e9+7;
class Solution {
public:

    // stack

    vector<int>findNse(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>ans(n,n);
        
        stack<int>st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int>findPse(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>ans(n,-1);
        
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse=findNse(arr),pse=findPse(arr);

        long long ans=0;
        for(int i=0;i<n;i++)
            ans+=(((1LL*(i-pse[i]+mod)*(nse[i]-i+mod))%mod)*arr[i])%mod;
        return ans%mod;
    }
};