class Solution {
public:

    // array shud be sorted rotated else -1
    // my claim is 
    // do one of things
    // if reversed , unreverse it 
    // then simply find min dis of a from 0 cyclically or acylically

    int n;

    bool fail(vector<int>& arr) // -1 case
    {
        int idx=-1;
        for(int i=0;i<n;i++)
            if(!arr[i])
            {
                idx=i;
                break;
            }
        bool inc=0;
        if(arr[(idx+1)%n]==1)
            inc=1;
        else if(arr[(idx+1)%n]!=n-1)
            return 1;
        
        if(inc)
        {
            int prev=arr[idx];
            int i=(idx+1)%n;
            while(i!=idx)
            {
                if(arr[i]<prev)
                    return 1;
                prev=arr[i];
                i=(i+1)%n;
            }
        }
        else
        {
            int prev=arr[idx];
            int i=(idx-1+n)%n;
            while(i!=idx)
            {
                if(arr[i]<prev)
                    return 1;
                prev=arr[i];
                i=(i-1+n)%n;
            }
        }
        return 0;
    }

    int minOperations(vector<int>& arr) {
        n=arr.size();
        if(n==1)
            return 0;
        if(fail(arr))
            return -1;
        
        int idx=-1;
        for(int i=0;i<n;i++)
            if(!arr[i])
            {
                idx=i;
                break;
            }

        int ans=0;
        if(!(arr[(idx+1)%n]==1)) // dec h 
            ans=1+min(n-idx-1,(idx+1)%n);
        else
            ans=min(idx,2+n-idx);
        return ans;
    }
};