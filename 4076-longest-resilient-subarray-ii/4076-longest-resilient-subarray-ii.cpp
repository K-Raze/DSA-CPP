using ll=long long;
class Solution {
public:
    
    int resilientSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        for(int& x : arr)
                x%=k;
        
        int ans=1;
        int temp=1;
        int l=0;
        ll sum=arr[0];
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
            {
                sum=(sum+arr[i])%k;
                if(sum%k==arr[i])
                    ans=max(ans,i-l+1);
                temp++;
            }
            else
            {
                sum=arr[i];
                temp=1;
                l=i;
            }
        }
        return ans;
    }
};