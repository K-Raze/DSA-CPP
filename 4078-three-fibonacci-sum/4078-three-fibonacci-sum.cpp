using ll=long long;
class Solution {
public:
    bool threeFibonacciSum(int n) {
        vector<ll>fib={0,1,1};
        while(fib[fib.size()-1]+fib[fib.size()-2]+fib[fib.size()-3]<n)
                fib.push_back(fib[fib.size()-1]+fib[fib.size()-2]);
        if(fib[fib.size()-1]+fib[fib.size()-2]+fib[fib.size()-3]==n)
            return 1;
        return 0;
    }
};