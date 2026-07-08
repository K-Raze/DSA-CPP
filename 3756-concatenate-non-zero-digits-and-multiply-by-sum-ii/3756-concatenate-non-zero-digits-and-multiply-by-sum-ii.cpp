const int mod=1e9+7;
class Solution {
public:

    // a
    // 10a+b
    // 100a+10b+c
    // 1000a+100b+10c+d
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();

        vector<int>pow10(n+1,1);
        for(int i=1;i<=n;i++)
            pow10[i]=(1LL*pow10[i-1]*10)%mod;

        vector<int>valPre(n),sumPre(n),cntPre(n);

        sumPre[0]=s.front()-'0';
        cntPre[0]=(s.front()!='0');

        if(s.front()!='0')
            valPre[0]=s.front()-'0';
        else
            valPre[0]=0;

        for(int i=1;i<n;i++)
        {
            sumPre[i]=(sumPre[i-1]+s[i]-'0')%mod;
            cntPre[i]=cntPre[i-1]+(s[i]!='0');

            if(s[i]!='0')
                valPre[i]=(10LL*valPre[i-1]+s[i]-'0')%mod;
            else
                valPre[i]=valPre[i-1];
        }

        vector<int>ans;
        for(auto&it : queries)
        {
            int l=it[0],r=it[1];

            int digits=cntPre[r];
            if(l-1>=0)
                digits-=cntPre[l-1];

            int x=valPre[r];
            if(l-1>=0)
                x=(x-(1LL*valPre[l-1]*pow10[digits])%mod+mod)%mod;

            int sum=sumPre[r];
            if(l-1>=0)
                sum=(sum-sumPre[l-1]+mod)%mod;

            ans.push_back((1LL*x*sum)%mod);
        }
        return ans;
    }
};