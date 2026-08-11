class Solution {
public:
    int missingInteger(vector<int>& arr) {

        unordered_map<int,bool>mp;
        for(int& x : arr)
            mp[x]=1;
        int sum=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==arr[i-1]+1)
                sum+=arr[i];
            else
                break;
        }
        while(sum)
        {
            if(!mp[sum])
                return sum;
            sum++;
        }
        return 0;
    }
};