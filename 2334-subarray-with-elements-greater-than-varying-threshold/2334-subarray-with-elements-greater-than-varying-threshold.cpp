class Solution {
public:

    public:
        vector<int> parent_dsu, size_dsu;

    void dsu_init(int n)
    {
        parent_dsu.resize(n);
        size_dsu.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent_dsu[i] = i;
    }

    int ultParent(int x)
    {
        if (parent_dsu[x] == x)
            return x;
        return parent_dsu[x] = ultParent(parent_dsu[x]);
    }

    void unionBySize(int a, int b)
    {
        a = ultParent(a);
        b = ultParent(b);
        if (a == b)
            return;
        if (size_dsu[a] < size_dsu[b])
            swap(a, b);
        parent_dsu[b] = a;
        size_dsu[a] += size_dsu[b];
    }

    // len less         len more
    // th more          th less

    int validSubarraySize(vector<int>& arr, int threshold) {
        int n=arr.size();
        dsu_init(n);

        set<pair<int,int>>st;
        vector<bool>in(n,0);

        for(int i=0;i<n;i++)
            st.insert({arr[i],i});

        for(int len=1;len<=n;len++)
        {
            int th=(threshold+len-1)/len;
            if(threshold%len==0)
                th=threshold/len+1;
            auto it=st.lower_bound({th,-1});
            while(it!=st.end())
            {
                int idx=it->second;
                in[idx]=1;
                if(idx+1<n && in[idx+1])
                    unionBySize(idx,idx+1);
                if(idx-1>=0 && in[idx-1])
                    unionBySize(idx,idx-1);
                int par=ultParent(idx);
                if(size_dsu[par]>=len)
                    return len;
                it=st.erase(it);
            }
        }
        return -1;
    }
};