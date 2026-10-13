class Solution {
public:

    // a b c d e
    // a&b c d&e
    // msb-> lsb
    // scene is agar koi 1 ho skti h to agli bits check ke time 
    // use sathme check krna
    // g groups
    // n-1 - (g-1) // merges
    // n-g merges
    // n-g <= k
    // g>=n-k
    // groups >= n-k

    int minOrAfterOperations(vector<int>& arr, int k) {
        int n=arr.size();

        int maskOff=0;
        int minGroup=n-k;

        for(int bit=29;bit>=0;bit--)
        {
            int maskTry=(maskOff | (1<<bit));

            int group=0;
            int currAnd=-1;

            for(int& val : arr)
            {
                currAnd&=val;
                
                if(!(currAnd & maskTry))
                {
                    group++;
                    currAnd=-1;
                }
            }

            if(group>=minGroup)
                maskOff=maskTry;
        }
        return (((1<<30)-1)^maskOff);
    }
};