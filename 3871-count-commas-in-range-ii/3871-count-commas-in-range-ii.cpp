using ll=long long;
class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000LL)
            return 0;
        else if(n<1000000LL)
            return n-999;
        else if(n<1000000000LL)
            return (1000000LL-1000LL)+(n-1000000LL+1)*2LL;
        else if(n<1000000000000LL)
             return (1000000LL-1000LL)+(1000000000LL-1000000LL)*2LL+(n-1000000000LL+1)*3LL;
        else if(n<1000000000000000LL)
            return (1000000LL-1000LL)+(1000000000LL-1000000LL)*2LL+(1000000000000LL-1000000000LL)*3LL+(n-1000000000000LL+1)*4LL;
        else
            return (1000000LL-1000LL)+(1000000000LL-1000000LL)*2LL+(1000000000000LL-1000000000LL)*3LL+(1000000000000000LL-1000000000000LL)*4LL+(n-999999999999999)*5LL;
    }
};