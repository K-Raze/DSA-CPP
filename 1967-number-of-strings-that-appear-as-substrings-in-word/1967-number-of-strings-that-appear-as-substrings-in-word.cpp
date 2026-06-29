class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,bool>cnt;
        for(int i=0;i<word.size();i++)
        {
            string curr;
            for(int j=i;j<word.size();j++)
            {
                curr+=word[j];
                cnt[curr]=1;
            }
        }
        int ans=0;
        for(string& s : patterns)
            if(cnt[s])
                ans++;
        return ans;
    }
};