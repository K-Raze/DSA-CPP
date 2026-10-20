class Solution {
public:

    int n;

    bool check(vector<int>& arr,int k)
    {
        int idx=0;
        int prevMax=0;
        while(idx<n)
        {   
            int cnt=0;
            int currMax=arr[idx];
            int currMin=arr[idx];
            for(int i=idx;i<idx+k;i++)
            {
                currMax=max(currMax,arr[i]);
                currMin=min(currMin,arr[i]);
                int ri=i+1;
                if(ri==idx+k)
                    ri=idx;
                if(arr[i]>arr[ri])
                    cnt++;
            }
            
            if(cnt>1 || prevMax>currMin)
                return 0;
            prevMax=currMax;
            idx+=k;
        }
        return 1;
    }


    int sortableIntegers(vector<int>& arr) {
        n=arr.size();
        int ans=0;
        for(int i=1;i*i<=n;i++)
            if(n%i==0)
            {
                if(check(arr,i))
                    ans+=i;
                if(n/i!=i)
                    if(check(arr,n/i))
                        ans+=n/i;
            }
        return ans;
    }
};