class Solution {
public:
    int countCommas(int n) {
        n-=min(n,999);
        return n;
    }
};