class Solution {
public:
    int maxLength(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int g=0,l=1,p=1;
            for(int j=i;j<n;j++)
            {
                p*=arr[j];
                if(p>25200)
                    break;
                g=gcd(g,arr[j]);
                l=lcm(l,arr[j]);
                if(p==l*g)
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};