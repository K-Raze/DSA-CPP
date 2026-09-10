class Solution {
public:

    inline int giveDig(int n)
    {
        string s=to_string(n);
        return s.size();
    }

    int giveOptLen(string& s,int lim)
    {
        int aSum=0;
        for(int b=1;b<=s.size();b++)
        {
            int digB=giveDig(b);
            // cout<<digB<<" ";
            aSum+=digB;
            if(digB+digB+3>=lim)
                return -1;
            // cout<<aSum<<" ";
            int totalLen=(3+digB)*b+aSum;
            // cout<<b<<" "<<totalLen<<endl;
            if(lim*b-totalLen>=s.size())
                return b;
        }
        return -1;
    }

    vector<string> splitMessage(string s, int limit) {
        int b=giveOptLen(s,limit);
        if(b==-1)
            return {};
        
        // construct
        int a=1;
        int idx=0;
        vector<string>ans;
        while(a<=b)
        {
            int rem=limit-(3+giveDig(a)+giveDig(b));
            string temp;
            if(a!=b)
                temp=s.substr(idx,rem);
            else
                temp=s.substr(idx);
            temp+='<'+to_string(a)+'/'+to_string(b)+'>';
            ans.push_back(temp);
            idx+=rem;
            a++;
        }
        return ans;
    }
};