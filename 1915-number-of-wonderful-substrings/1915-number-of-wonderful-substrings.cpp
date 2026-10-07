using ll=long long;
class Solution {
public:
    long long wonderfulSubstrings(string s) {
        unordered_map<ll,ll>xorCnt;
        xorCnt[0]++;

        ll pre=0;
        ll ans=0;

        for(char& ch : s)
        {
            pre^=(1<<(ch-'a'));
            ans+=xorCnt[pre];
            for(int bit=0;bit<10;bit++)
            {
                int nPre=(pre ^ (1<<bit));
                if(xorCnt.find(nPre)!=xorCnt.end())
                    ans+=xorCnt[nPre];
            }
            xorCnt[pre]++;
        }
        return ans;
    }
};