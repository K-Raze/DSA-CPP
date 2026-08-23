class Solution {
public:

    // 1 3
    // 14 5

    // alice bade ko or bada krega 
    // chote pe 0 lagadega
    // bob bade pe 0 lgayega , chote pe 9

    bool sumGame(string s) {
        int n=s.size();
        int leftSum=0,rightSum=0,leftQ=0,rightQ=0;
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!='?')
                leftSum+=s[i]-'0';
            else
                leftQ++;
        }
        for(int i=n/2;i<n;i++)
        {
            if(s[i]!='?')
                rightSum+=s[i]-'0';
            else
                rightQ++;
        }
        if(leftQ==rightQ)
            return leftSum!=rightSum;
        else if(leftQ>rightQ)
        {
            leftQ-=rightQ;
            if(leftSum>=rightSum)
                return 1;
            else
            {
                int aliceMin=leftSum;
                int aliceMax=leftSum+((leftQ+1)/2)*9;
                if(aliceMax>rightSum)
                    return 1;
                if(aliceMin+(leftQ/2)*9<rightSum)
                    return 1;
                return 0;
            }
        }
        else
        {
            rightQ-=leftQ;
            if(leftSum<=rightSum)
                return 1;
            else
            {
                int aliceMin=rightSum;
                int aliceMax=rightSum+((rightQ+1)/2)*9;
                // cout<<aliceMin<<" "<<aliceMax;
                if(aliceMax>leftSum)
                    return 1;
                if(aliceMin+(rightQ/2)*9<leftSum)
                    return 1;
                return 0;
            }
        }
        return 0;
    }
};