class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>cnt(10,0);
        for(int x : digits)
            cnt[x]++;
        int ans=0;
        for(int val=100;val<1000;val+=2)
        {
            vector<int>currCnt(10,0);
            string s=to_string(val);
            for(char& ch : s)
                currCnt[ch-'0']++;
            bool good=1;
            for(int i=0;i<10;i++)
                if(currCnt[i]>cnt[i])
                    good=0;
            ans+=good;
        }
        return ans;
    }
};