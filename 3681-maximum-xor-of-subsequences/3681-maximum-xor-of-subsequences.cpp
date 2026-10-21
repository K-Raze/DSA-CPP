class Solution {
public:

    struct xorBasis
    {
        vector<int>basis;

        xorBasis()
        {
            basis.assign(32,0);
        }

        void insert(int x)
        {
            for(int i=30;i>=0;i--)
                if((x>>i)&1)
                {
                    if(basis[i]==0)
                    {
                        basis[i]=x;
                        return;
                    }
                    x^=basis[i];
                }
        }

        int getMax()
        {
            int ans=0;
            for(int i=30;i>=0;i--)
                if((ans^basis[i])>ans)
                    ans^=basis[i];
            return ans;
        }
    };

    int maxXorSubsequences(vector<int>& arr) {
        xorBasis xb;
        for(int& x : arr)
            xb.insert(x);
        return xb.getMax();
    }
};