using ll=long long;
class Solution {
public:

    int nthUglyNumber(int n, int a, int b, int c) {
        ll start=1,end=2e9;
        ll A=a;
        ll B=b;
        ll C=c;
        ll ab = std::lcm(A, B);
        ll bc = std::lcm(B, C);
        ll ca = std::lcm(C, A);
        ll abc = std::lcm(ab, C);

        while(start<=end)
        {
            ll val=start+((end-start)>>1);

            // is thi val nth ?
            ll pos=val/a+val/b+val/c;
            pos-=val/ab;
            pos-=val/bc;
            pos-=val/ca;
            pos+=val/abc;

            if(pos>=n)
                end=val-1;
            else
                start=val+1;
        }
        return start;
    }
};