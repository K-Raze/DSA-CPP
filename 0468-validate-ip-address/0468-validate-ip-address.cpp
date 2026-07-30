class Solution {
public:

    bool validateIpv4(string& s)
    {
        if(s.empty() || (s.front()=='0' && s.size()>1) || s.size()>3)
            return 0;

        // only numbers
        for(char& ch : s)
            if(!(ch>='0' && ch<='9'))
                return 0;

        int val=stoi(s);
        return (val>=0 && val<256);
    }

    bool validateIpv6(string& s)
    {
        if(!(s.size()>=1 && s.size()<=4))
            return 0;
        // only numbers
        for(char& ch : s)
            if(!(ch>='0' && ch<='9') && !(ch>='a' && ch<='f') && !(ch>='A' && ch<='F'))
                return 0;
        return 1;
    }

    bool check(string& s,char delim)
    {
        int cnt=0;
        stringstream ss(s);
        
        string temp;
        while(getline(ss,temp,delim))
        {
            if(delim=='.')
                if(!validateIpv4(temp))
                    return 0;
            if(delim==':')
                if(!validateIpv6(temp))
                    return 0;
            cnt++;
        }
        if(delim=='.')
            return cnt==4;
        return cnt==8;
    }

    string validIPAddress(string queryIp) {
        if(queryIp.empty())
            return "Neither";
        if(queryIp.front()==':' || queryIp.back()==':')
            return "Neither";
        if(queryIp.front()=='.' || queryIp.back()=='.')
            return "Neither";
        for(char& ch : queryIp)
        {
            if(ch=='.')
            {
                if(check(queryIp,ch))
                    return "IPv4";
                else
                    return "Neither";
            }
            else if(ch==':')
            {
                if(check(queryIp,ch))
                    return "IPv6";
                else
                    return "Neither";
            }
        }
        return "Neither";
    }
};