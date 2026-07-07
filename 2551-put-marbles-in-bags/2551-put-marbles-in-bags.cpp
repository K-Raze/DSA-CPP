using ll=long long;
class Solution {
public:

    long long putMarbles(vector<int>& weights, int k) {
        vector<ll>arr;
        for(int i=0;i<weights.size()-1;i++)
            arr.push_back(weights[i]+weights[i+1]);
        sort(arr.rbegin(),arr.rend());
        ll maxScore=0;
        for(int i=0;i<k-1;i++)
            maxScore+=arr[i];
        maxScore+=weights.front()+weights.back();
        sort(arr.begin(),arr.end());
        ll minScore=0;
        for(int i=0;i<k-1;i++)
            minScore+=arr[i];
        minScore+=weights.front()+weights.back();
        return maxScore-minScore;
    }
};