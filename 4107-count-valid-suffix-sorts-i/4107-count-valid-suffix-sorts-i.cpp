class Solution {
public:
    int countSuffix(vector<int>& arr, vector<int>& target) {
        int idx=target.size()-1;
        {
            int j=target.size()-2;
            while(j>=0 && target[j]>=target[j+1])
                j--;
            j++;
            idx=j;
        }
        int match=-1;
        {
            int j=0;
            while(j<arr.size() && arr[j]==target[j])
                j++;
            match=j-1;
        }

        unordered_map<int,int>mp;
        int ans=0;
        int diff=0;
        for(int j=arr.size()-1;j>=idx;j--)
        {
            int a=arr[j],b=target[j];
            mp[a]++;
            if(!mp[a])  
                diff--;
            else if(mp[a]==1)
                diff++;
            mp[b]--;
            if(!mp[b])  
                diff--;
            else if(mp[b]==-1)
                diff++;
            if(!diff && j-1<=match)
                ans++;
        }
        return ans;
    }
};