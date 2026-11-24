using ll=long long;
class Solution {
public:
    char kthCharacter(long long pos, vector<int>& operations) {
        ll currLen=1;
        ll step=-1;
        while(currLen<pos)
        {
            currLen<<=1;
            step++;
        }

        ll prev=0;

        while(step>-1)
        {
            bool op=operations[step];
            ll prevLen=currLen/2;

            if(pos>prevLen)
            {
                if(op)
                    prev++;
                pos-=prevLen;
            }
            step--;
            currLen=prevLen;
        }
        
        return 'a'+prev%26;
    }
};