class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return 1;

        int r=n-1;
        {
            for(int i=n-2;i>=0;i--)
            {
                if(arr[i]<=arr[i+1])
                    r=i;
                else
                    break;
            }
        }
        int l=0;
        {
            for(int i=1;i<n;i++)
            {
                if(arr[i]>=arr[i-1])
                    l=i;
                else
                    break;
            }
        }
        // cout<<l<<" "<<r;
        if(r<=1)
            return 1;
        if(l>=n-2)
            return 1;
        if(l+1==r && (arr[l-1]<=arr[r] || arr[r+1]>=arr[l]))
            return 1;
        if(l+2==r && arr[l]<=arr[r])
            return 1;
        return 0;

    }
};
