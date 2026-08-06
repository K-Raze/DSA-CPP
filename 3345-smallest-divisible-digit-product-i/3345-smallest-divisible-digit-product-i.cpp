class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n)
        {
            string s=to_string(n);
            int val=1;
            for(char& ch : s)
            {
                val=val*(ch-'0');
                val%=t;
            }
            if(!val)
                return n;
            n++;
        }
        return n;
    }
};