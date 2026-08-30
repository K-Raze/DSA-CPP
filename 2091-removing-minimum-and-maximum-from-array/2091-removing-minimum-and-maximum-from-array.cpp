class Solution {
public:
    int minimumDeletions(vector<int>& arr) {
        int n=arr.size();
        int i1=max_element(arr.begin(),arr.end())-arr.begin();
        int i2=min_element(arr.begin(),arr.end())-arr.begin();
        return min({max(i1,i2)+1,n-min(i1,i2),min(i1,i2)+1+n-max(i1,i2)});
    }
};