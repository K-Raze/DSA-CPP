using ll=long long;
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

    vector<int>findNge(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>ans(n,n);
        
        stack<int>st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int>findPge(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>ans(n,-1);
        
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]<arr[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        ll ans=0;
        vector<int>nse=findNse(arr),pse=findPse(arr);
        vector<int>nge=findNge(arr),pge=findPge(arr);

        for(int i=0;i<n;i++)
            ans-=1LL*(i-pse[i])*(nse[i]-i)*arr[i];
        for(int i=0;i<n;i++)
            ans+=1LL*(i-pge[i])*(nge[i]-i)*arr[i];
        return ans;
    }
};