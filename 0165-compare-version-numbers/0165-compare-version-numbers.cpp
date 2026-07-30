class Solution {
public:

    int compareVersion(string s1, string s2) {
        stringstream ss1(s1);
        stringstream ss2(s2);

        string num1,num2;
        while(getline(ss1,num1,'.') && getline(ss2,num2,'.'))
        {
            if(stoi(num1)<stoi(num2))
                return -1;
            else if(stoi(num1)>stoi(num2))
                return 1;
            num1.clear();
            num2.clear();
        }
        if(!num1.empty() && stoi(num1))
            return 1;
        if(!num2.empty() && stoi(num2))
            return -1;
        while(getline(ss1,num1,'.'))
            if(stoi(num1))
                return 1;
        while(getline(ss2,num2,'.'))
            if(stoi(num2))
                return -1;
        return 0;
    }
};