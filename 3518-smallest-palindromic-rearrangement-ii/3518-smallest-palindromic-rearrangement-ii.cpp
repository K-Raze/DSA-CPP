using ll = long long;

class Solution {
public:

    ll ncr(int n,int r,ll lim)
    {
        if(r>n) return 0;
        r=min(r,n-r);
        ll ans=1;
        for(int i=1;i<=r;i++)
        {
            ans=ans*(n-r+i)/i;
            if(ans>=lim) return lim;
        }
        return ans;
    }

    ll countWay(vector<int>& cnt,int target)
    {
        ll ans=1;
        int total=0;
        for(int x : cnt)
            total+=x;

        int rem=total;
        for(int x : cnt)
        {
            if(x==0) continue;
            ans*=ncr(rem,x,(ll)target+1);
            if(ans>target) return target+1;
            rem-=x;
        }
        return ans;
    }

    string smallestPalindrome(string s, int target) {
        int n=s.size();
        vector<int>cnt(26,0);
        
        for(char ch : s)
            cnt[ch-'a']++;

        char mid=0;
        for(int i=0;i<26;i++)
        {
            if(cnt[i]&1)
                mid='a'+i;
            cnt[i]/=2;
        }

        if (countWay(cnt, target) < target)
            return "";

        string temp;

        for(int i=0;i<n/2;i++)
            for(char ch='a';ch<='z';ch++)
            {
                if(cnt[ch-'a']==0)
                    continue;

                cnt[ch-'a']--;

                ll ways=countWay(cnt,target);

                if(target>ways)
                {
                    target-=ways;
                    cnt[ch-'a']++;
                }
                else
                {
                    temp+=ch;
                    break;
                }
            }
        string rev=temp;
        reverse(rev.begin(),rev.end());

        if(mid)
            return temp+mid+rev;
        return temp+rev;
    }
};