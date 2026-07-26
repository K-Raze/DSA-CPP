class Solution {
public:

    int maximumProduct(vector<int>& arr) {
        int n=arr.size();
        vector<int>pos,neg;
        for(int&x : arr)
        {
            if(x>=0)
                pos.push_back(x);
            else
                neg.push_back(x);
        }
        sort(arr.begin(),arr.end());
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        int ans=arr[n-1]*arr[n-2]*arr[n-3];
        if(neg.size()>=2 && pos.size()>=1)
            ans=max(ans,neg[0]*neg[1]*pos.back());
        return ans;
    }
};