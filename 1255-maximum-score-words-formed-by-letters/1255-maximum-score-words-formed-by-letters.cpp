class Solution {
public:

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        vector<int>ogCnt(26,0);
        for(char& ch : letters)
            ogCnt[ch-'a']++;

        int ans=0;

        int n=words.size();

        for(int mask=1;mask<(1<<n);mask++)
        {
            vector<int>cnt(26,0);
            for(int i=0;i<n;i++)
                if((mask>>i)&1)
                    for(char& ch : words[i])
                        cnt[ch-'a']++;
            bool good=1;
            for(int i=0;i<26;i++)
                if(cnt[i]>ogCnt[i])
                {
                    good=0;
                    break;
                }
            if(!good)
                continue;
            int cost=0;
            for(int i=0;i<26;i++)
                cost+=cnt[i]*score[i];
            ans=max(ans,cost);
        }
        return ans;
    }
};