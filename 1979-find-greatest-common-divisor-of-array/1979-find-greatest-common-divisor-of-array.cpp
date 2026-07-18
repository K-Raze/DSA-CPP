class Solution {
public:
    int findGCD(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        return __gcd(arr.front(),arr.back());
    }
};