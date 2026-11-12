class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>ans;
        for(int i=0;i<s1.size();i++)
        {
            string t1,t2;
            int j=i;
            while(j<s1.size() && s1[j]!=s2[j])
            {
                t1+=s1[j];
                t2+=s2[j];
                j++;
            }
            if(j!=i)
            {
                ans.push_back({t1,t2});
                i=j;
                i--;
            }
        }
        return ans;
    }
};