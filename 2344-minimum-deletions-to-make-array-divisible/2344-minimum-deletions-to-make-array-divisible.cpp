class Solution {
public:

    int minOperations(vector<int>& arr, vector<int>& numsDivide) {
        int val=0;
        for(int& x : numsDivide)
            val=gcd(val,x);
        
        sort(arr.begin(),arr.end());
        int n=arr.size();

        for(int i=0;i<n;i++)
        {
            if(arr[i]>val)
                return -1;
            if(val%arr[i]==0)
                return i;
        }
        return -1;
    }
};