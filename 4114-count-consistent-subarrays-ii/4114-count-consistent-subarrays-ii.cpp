using ll=long long;
class Solution {
public:

    vector<int>giveNse(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>ans(n,n);

        stack<int>st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int>givePse(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>ans(n,-1);

        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i]<arr[st.top()])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }

        return ans;
    }

    vector<vector<int>> giveN0bit(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>temp(31,n);
        vector<vector<int>>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            for(int bit=30;bit>=0;bit--)
                if(!((arr[i]>>bit)&1))
                    temp[bit]=i;
            ans[i]=temp;
        }
        return ans;
    }

    vector<vector<int>> giveP0bit(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>temp(31,-1);
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++)
        {
            for(int bit=30;bit>=0;bit--)
                if(!((arr[i]>>bit)&1))
                    temp[bit]=i;
            ans[i]=temp;
        }
        return ans;
    }

    long long countConsistent(vector<int>& arr) {
        int n=arr.size();

        vector<int>nse=giveNse(arr);
        vector<int>pse=givePse(arr);
        vector<vector<int>>n0bit=giveN0bit(arr);
        vector<vector<int>>p0bit=giveP0bit(arr);

        ll ans=0;

        for(int i=0;i<n;i++)
        {
            ll l=pse[i];
            for(int bit=30;bit>=0;bit--)
                if((arr[i]>>bit)&1)
                    l=max(l,(ll)p0bit[i][bit]);

            ll r=nse[i];
            for(int bit=30;bit>=0;bit--)
                if((arr[i]>>bit)&1)
                    r=min(r,(ll)n0bit[i][bit]);
            
            ans+=(i-l)*(r-i);
        }
        return ans;
    }
};