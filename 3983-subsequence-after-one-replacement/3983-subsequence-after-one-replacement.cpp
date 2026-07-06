class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if (n == 1 && m >= 1)
            return 1;

        vector<int> preIdx(n, -1), suffIdx(n, -1);
        
        int i = 0;
        for (int j = 0; j < m && i < n; j++)
            if (s[i] == t[j])
            {
                preIdx[i] = j;
                i++;
            }
        
        i = n - 1;
        for (int j = m - 1; j >= 0 && i >= 0; j--)
            if (s[i] == t[j])
            {
                suffIdx[i] = j;
                i--;
            }
        
        if (suffIdx[1] != -1 && suffIdx[1] > 0)
            return true;

        if (preIdx[n-2] != -1 && preIdx[n-2] < m - 1)
            return 1;
        
        for (int i = 1; i < n - 1; i++)
            if (preIdx[i-1] != -1 && suffIdx[i+1] != -1)
                if (suffIdx[i+1] - preIdx[i-1] > 1)
                    return true;
        
        return false;
    }
};