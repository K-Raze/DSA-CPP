using ll=long long;
class Solution {
public:

    vector<int>findPge(vector<int>& arr)
    {
        int n=arr.size();
        vector<int>ans(n,-1);
        
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
                st.pop();
            if(!st.empty())
                ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    // vector<int>findPse(vector<int>& arr)
    // {
    //     int n=arr.size();
    //     vector<int>ans(n,-1);
        
    //     stack<int>st;

    //     for(int i=0;i<n;i++)
    //     {
    //         while(!st.empty() && arr[st.top()]>=arr[i])
    //             st.pop();
    //         if(!st.empty())
    //             ans[i]=st.top();
    //         st.push(i);
    //     }
    //     return ans;
    // }

    long long numberOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        ll ans=0;

        // vector<int>psiArr=findPse(arr);
        vector<int>pgiArr=findPge(arr);

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++)
        {
            auto& vec=mp[arr[i]];
            vec.push_back(i);
            // int psi=psiArr[i];
            int pgi=pgiArr[i];

            int idx=lower_bound(vec.begin(),vec.end(),pgi)-vec.begin();
            ans+=vec.size()-idx;
        }
        return ans;
    }
};