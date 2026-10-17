class Solution {
public: 

    // 18,43,34,16
    // 16, 34, 43, 18
    // 0 1 2 3
    // 3 2 1 0

    inline int giveDigSum(int n)
    {
        string s=to_string(n);
        int ans=0;
        for(char& ch : s)
            ans+=ch-'0';
        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>temp;
        for(int& x : nums)
            temp.push_back({giveDigSum(x),x});
        sort(temp.begin(),temp.end());

        unordered_map<int,int>numIdx;
        for(int i=0;i<n;i++)
            numIdx[temp[i].second]=i;

        for(int& x : nums)
            x=numIdx[x];
        
        int ans=0;
        for(int i=0;i<n;i++)
            while(i!=nums[i])
            {
                ans++;
                swap(nums[i],nums[nums[i]]);
            }
        return ans;
    }
};