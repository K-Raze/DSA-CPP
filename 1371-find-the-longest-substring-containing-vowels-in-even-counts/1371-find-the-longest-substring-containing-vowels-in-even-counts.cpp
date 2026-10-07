class Solution {
public:

    int giveIdx(char ch)
    {
        if(ch=='a')
            return 0;
        if(ch=='e')
            return 1;
        if(ch=='i')
            return 2;
        if(ch=='o')
            return 3;
        if(ch=='u')
            return 4;
        return -1;
    }

    int findTheLongestSubstring(string s) {
        unordered_map<int,int>xorIdx;
        xorIdx[0]=-1;
        int ans=0;
        int pre=0;
        int i=0;
        for(char& ch : s)
        {
            int idx=giveIdx(ch);
            if(idx!=-1)
                pre^=(1<<idx);
            if(xorIdx.find(pre)!=xorIdx.end())
                ans=max(ans,i-xorIdx[pre]);
            else
                xorIdx[pre]=i;
            i++;
        }
        return ans;
    }
};