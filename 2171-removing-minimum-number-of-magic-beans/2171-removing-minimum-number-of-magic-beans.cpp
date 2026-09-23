using ll=long long;
class Solution {
public:
    long long minimumRemoval(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        ll s=0,b=accumulate(arr.begin(),arr.end(),0LL)-arr.front();
        ll ans=b;
        for(int i=0;i<arr.size();i++)
        {
            ans=min(ans,s+b-1LL*((ll)arr.size()-(i+1))*arr[i]);
            if(i+1<arr.size())
                b-=arr[i+1];
            s+=arr[i];
        }
        return ans;
    }
};