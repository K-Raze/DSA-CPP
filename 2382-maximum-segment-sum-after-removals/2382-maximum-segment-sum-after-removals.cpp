using ll=long long;
class Solution {
public:

    vector<ll> parentDsu, sizeDsu;
    void dsuInit(int n)
    {
        parentDsu.resize(n);
        sizeDsu.assign(n, 0LL);
        for(int i=0;i<n;i++)
            parentDsu[i]=i;
    }

    int ultParent(int x)
    {
        return x==parentDsu[x]
               ? x
               : parentDsu[x]=ultParent(parentDsu[x]);
    }

    void unionBySize(int a,int b)
    {
        a=ultParent(a);
        b=ultParent(b);
        if(a==b)
            return;
        if(sizeDsu[a]<sizeDsu[b])
            swap(a,b);
        parentDsu[b]=a;
        sizeDsu[a]+=sizeDsu[b];
    }

    vector<long long> maximumSegmentSum(vector<int>& arr, vector<int>& rmq) {
        int n=arr.size();

        dsuInit(n);

        vector<bool>in(n,0);
        reverse(rmq.begin(),rmq.end());
        vector<ll>ans;
        ll maxSum=0;

        for(int& idx : rmq)
        {
            ans.push_back(maxSum);
            in[idx]=1;
            if(idx+1<n && in[idx+1])
                unionBySize(idx,idx+1);
            if(idx-1>=0 && in[idx-1])
                unionBySize(idx,idx-1);
            int par=ultParent(idx);
            sizeDsu[par]+=arr[idx];
            maxSum=max(maxSum,sizeDsu[par]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};