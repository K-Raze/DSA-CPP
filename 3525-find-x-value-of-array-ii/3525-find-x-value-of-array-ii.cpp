class Solution {
public:


// ============== NORMAL SEGMENT TREE ===============

struct node
{
    int prod;
    array<int, 5> modCnt;
    node()
    {
        modCnt.fill(0);
    }
};

class SegmentTree
{
public:
    int n;
    int k;
    vector<node> seg;

    inline node merge(const auto &l, const auto &r)
    {
        node ans;
        ans.prod = (l.prod * r.prod) % k;
        ans.modCnt = l.modCnt;
        for (int i = 0; i < k; i++)
        {
            int nMod = (l.prod * i) % k;
            ans.modCnt[nMod] += r.modCnt[i];
        }
        return ans;
    }

    SegmentTree(int n, int k, vector<int> &arr)
    {
        this->n = n;
        this->k = k;
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int i, int l, int r, vector<int> &arr)
    {
        if (l == r)
        {
            seg[i].prod = arr[l] % k;
            seg[i].modCnt[arr[l] % k] = 1;
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(2 * i + 1, l, mid, arr);
        build(2 * i + 2, mid + 1, r, arr);
        seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
    }

    node query(int i, int l, int r, int ql, int qr) {
        if (l >= ql && r <= qr)
            return seg[i];
        
        int mid = l + ((r - l) >> 1);
        
        if (qr <= mid)
            return query(2 * i + 1, l, mid, ql, qr);
        else if (ql > mid)
            return query(2 * i + 2, mid + 1, r, ql, qr);
        else
            return merge(query(2 * i + 1, l, mid, ql, qr), query(2 * i + 2, mid + 1, r, ql, qr));
    }

    void pointUpdate(int i, int l, int r, int idx, int val)
    {
        if (l == r)
        {
            seg[i].prod = val % k;
            seg[i].modCnt.fill(0);
            seg[i].modCnt[val % k] = 1;
            return;
        }
        int mid = l + ((r - l) >> 1);
        if (idx <= mid)
            pointUpdate(2 * i + 1, l, mid, idx, val);
        else
            pointUpdate(2 * i + 2, mid + 1, r, idx, val);
        seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
    }
};
// --------------------------------------------------

    vector<int> resultArray(vector<int>& arr, int k, vector<vector<int>>& queries) {
        int n=arr.size();

        SegmentTree st(n,k,arr);
        vector<int>ans;

        for(auto& it : queries)
        {
            int idx=it[0],val=it[1],start=it[2],xi=it[3];
            st.pointUpdate(0,0,n-1,idx,val);
            ans.push_back(st.query(0,0,n-1,start,n-1).modCnt[xi]);
        }
        return ans;
    }
};