class Solution {
public:

    // 1|001100011100011000111000|1

    int solvezo(vector<int>& arr)
    {
        int ans=0;
        int total=0;
        for(int i=1;i<arr.size();i+=2)
        {
            ans+=arr[i];
            total+=arr[i];
        }
        for(int i=1;i<arr.size()-1;i+=2)
        {
            int temp=arr[i]+arr[i-1]+arr[i+1];
            temp+=total-arr[i];
            ans=max(ans,temp);
        }
        return ans;
    }

    int solveoz(vector<int>& arr)
    {
        int ans=0;
        int total=0;
        for(int i=0;i<arr.size();i+=2)
        {
            ans+=arr[i];
            total+=arr[i];
        }
        for(int i=2;i<arr.size()-1;i+=2)
        {
            int temp=arr[i]+arr[i-1]+arr[i+1];
            temp+=total-arr[i];
            ans=max(ans,temp);
        }
        return ans;
    }

    int maxActiveSectionsAfterTrade(string s) {
        vector<int>arr;
        {
            int temp=1;
            for(int i=1;i<s.size();i++)
            {
                if(s[i]==s[i-1])
                    temp++;
                else
                {
                    arr.push_back(temp);
                    temp=1;
                }
            }
            arr.push_back(temp);
        }
        if(s.front()=='0')
            return solvezo(arr);
        return solveoz(arr);
    }
};