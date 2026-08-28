class Solution {
public:
    string lexPalindromicPermutation(string s, string tar) {
        int n = s.size();
        if(n==1)
        {
            if(s>tar)
                return s;
            return "";
        }
        vector<int> cnt(26, 0);
        for (char &ch : s)
            cnt[ch - 'a']++;
        // validate pal
        bool odd = 0;
        char chOdd;
        {
            for (int i = 0; i < 26; i++)
            {
                if (cnt[i] & 1)
                {
                    if (odd)
                        return "";
                    else
                        odd = 1;
                    chOdd = i + 'a';
                    cnt[i]--;
                }
                cnt[i] /= 2;
            }
        }

        vector<int> cc = cnt;
        int hn = (n - 2) / 2;
        int ubIndex = -1;
        bool wrecked = 0;
        for (int i = 0; i <= hn; i++)
        {
            int idx = tar[i] - 'a';
            if (cnt[idx])
            {
                cnt[idx]--;
                for (int j = idx + 1; j < 26; j++)
                    if (cnt[j])
                        ubIndex = i;
            }
            else
            {
                bool find = 0;
                for (int j = idx + 1; j < 26; j++)
                    if (cnt[j])
                    {
                        find = 1;
                        break;
                    }
                if (!find && ubIndex == -1)
                    return "";
                if (find)
                    ubIndex = i;
                wrecked = 1;
                break;
            }
        }
        if (wrecked)
        {
            cnt = cc;
            string ans;
            for (int i = 0; i < ubIndex; i++)
            {
                ans += tar[i];
                cnt[tar[i] - 'a']--;
            }
            for (int j = tar[ubIndex] - 'a' + 1; j < 26; j++)
                if (cnt[j])
                {
                    ans += 'a' + j;
                    cnt[j]--;
                    break;
                }
            while (ans.size() != (hn + 1))
            {
                for (int j = 0; j < 26; j++)
                    if (cnt[j])
                    {
                        ans += 'a' + j;
                        cnt[j]--;
                        break;
                    }
            }
            if (odd)
                ans += chOdd;
            if (s.size() & 1)
            {
                int idx = ans.size() - 2;
                while (idx >= 0)
                    ans += ans[idx--];
            }
            else
            {
                int idx = ans.size() - 1;
                while (idx >= 0)
                    ans += ans[idx--];
            }
            return ans;
        }
        else
        {
            string temp;
            cnt = cc;
            for (int i = 0; i <= hn; i++)
                temp += tar[i];
            if (odd)
                temp += chOdd;
            if (s.size() & 1)
            {
                int idx = temp.size() - 2;
                while (idx >= 0)
                    temp += temp[idx--];
            }
            else
            {
                int idx = temp.size() - 1;
                while (idx >= 0)
                    temp += temp[idx--];
            }
            if (temp > tar)
                return temp;
            if (ubIndex == -1)
                return "";
        }
        cnt = cc;
        string ans;
        for (int i = 0; i < ubIndex; i++)
        {
            ans += tar[i];
            cnt[tar[i] - 'a']--;
        }
        for (int j = tar[ubIndex] - 'a' + 1; j < 26; j++)
            if (cnt[j])
            {
                ans += 'a' + j;
                cnt[j]--;
                break;
            }
        while (ans.size() != (hn + 1))
        {
            for (int j = 0; j < 26; j++)
                if (cnt[j])
                {
                    ans += 'a' + j;
                    cnt[j]--;
                    break;
                }
        }
        if (odd)
            ans += chOdd;
        if (s.size() & 1)
        {
            int idx = ans.size() - 2;
            while (idx >= 0)
                ans += ans[idx--];
        }
        else
        {
            int idx = ans.size() - 1;
            while (idx >= 0)
                ans += ans[idx--];
        }
        return ans;
    }
};