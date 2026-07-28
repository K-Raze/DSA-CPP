class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>cnt(26,0);
        for(char& ch : s)
            cnt[ch-'a']++;
        
        string temp;
        char mid='*';
        for(char ch='a';ch<='z';ch++)
        {
            if(!cnt[ch-'a'])
                continue;
            int adder=cnt[ch-'a']/2;
            cnt[ch-'a']-=2*adder;
            while(adder--)
                temp+=ch;
            if(cnt[ch-'a']==1)
            {
                mid=ch;
                continue;
            }
        }
        if(s.size()&1)
        {
            temp+=mid;
            int i=temp.size()-2;
            while(i>=0)
                temp+=temp[i--];
        }
        else
        {
            int i=temp.size()-1;
            while(i>=0)
                temp+=temp[i--];
        }
        return temp;
    }

};