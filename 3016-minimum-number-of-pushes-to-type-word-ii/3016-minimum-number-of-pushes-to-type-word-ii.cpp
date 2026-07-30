class Solution {
public:
    int minimumPushes(string word) {
        vector<int>cnt(26,0);
        for(char& ch : word)
            cnt[ch-'a']++;
        
        sort(cnt.rbegin(),cnt.rend());
        while(cnt.back()==0)
            cnt.pop_back();
        reverse(cnt.begin(),cnt.end()); // dekh ise

        int val=1;
        int rem=8;

        int ans=0;
        while(!cnt.empty())
        {
            while(!cnt.empty() && rem--)
            {
                ans+=cnt.back()*val;
                cnt.pop_back();
            }
            rem=8;
            val++;
        }
        return ans;

    }
};