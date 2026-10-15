using ll = long long;
const ll mod = 1e9 + 7;

// lazy contains negatives 
// so.    do   ____+mod)%mod everywhere

class Solution
{
    //   pref ka b to segment bnayega na 
public:

    // dry run
    // 1 2 1
    // 1 2 2 distinc pref arr
    // pref[2]-pref[0]->-- 1 2
    // 8+1+5+1 good to go similar to 3721 ques 

    // make distinct pref arr
    // lst -> store square sum of range
    // suppose lazy have x
    // (a+x)^2= a^2+x^2+2*a*x
    // seg[i]+= 2x*(sum of range) + (r-l+1)*seg[i]
    // baki approach same as 3721 lc :)

    // ============== LAZY SEGMENT TREE =================
    class LazySegmentTree
    {
    public:
        int n;
        vector<ll> seg, lazy;
        vector<ll> pref;

        LazySegmentTree(int n, vector<ll> &arr)
        {
            this->n = n;
            seg.assign(4 * n, 0);
            pref.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
            build(0, 0, n - 1, arr);
        }

        void build(int i, int l, int r, vector<ll> &arr)
        {
            if (l == r)
            {
                seg[i] = (1LL * arr[l] * arr[l]) % mod;
                pref[i] = arr[l] % mod;
                return;
            }

            int mid = l + ((r - l) >> 1);
            build(2 * i + 1, l, mid, arr);
            build(2 * i + 2, mid + 1, r, arr);

            seg[i] = (seg[2 * i + 1] + seg[2 * i + 2]) % mod;
            pref[i] = (pref[2 * i + 1] + pref[2 * i + 2]) % mod;
        }

        void push(int i, int l, int r)
        {
            if (!lazy[i])
                return;

            ll pre = pref[i];

            seg[i] = (seg[i]
                      + (2LL * lazy[i] % mod * pre % mod) % mod
                      + ((r - l + 1) % mod * (lazy[i] * lazy[i] % mod) % mod) % mod) % mod;

            pref[i] = (pref[i]
                       + ((r - l + 1) % mod * lazy[i] % mod) % mod) % mod;

            if (l != r)
            {
                lazy[2 * i + 1] = (lazy[2 * i + 1] + lazy[i]) % mod;
                if (lazy[2 * i + 1] < 0) lazy[2 * i + 1] += mod;

                lazy[2 * i + 2] = (lazy[2 * i + 2] + lazy[i]) % mod;
                if (lazy[2 * i + 2] < 0) lazy[2 * i + 2] += mod;
            }

            lazy[i] = 0;
        }

        void update(int i, int l, int r, int ql, int qr, ll val)
        {
            if (ql > qr)
                return;

            push(i, l, r);

            if (qr < l || ql > r)
                return;

            if (l >= ql && r <= qr)
            {
                lazy[i] = (lazy[i] + val) % mod;
                if (lazy[i] < 0) lazy[i] += mod;
                push(i, l, r);
                return;
            }

            int mid = l + ((r - l) >> 1);

            update(2 * i + 1, l, mid, ql, qr, val);
            update(2 * i + 2, mid + 1, r, ql, qr, val);

            seg[i] = (seg[2 * i + 1] + seg[2 * i + 2]) % mod;
            pref[i] = (pref[2 * i + 1] + pref[2 * i + 2]) % mod;
        }

        ll query(int i, int l, int r, int ql, int qr)
        {
            push(i, l, r);

            if (qr < l || ql > r)
                return 0;

            if (l >= ql && r <= qr)
                return seg[i];

            int mid = l + ((r - l) >> 1);

            return (query(2 * i + 1, l, mid, ql, qr)
                    + query(2 * i + 2, mid + 1, r, ql, qr)) % mod;
        }
    };
    // --------------------------------------------------

    int sumCounts(vector<int> &arr)
    {
        int n = arr.size();

        // make distinct pref arr
        vector<ll> pre(n, 0);
        unordered_map<ll, set<ll>> nextOcc;

        for (int i = 0; i < n; i++)
        {
            ll val = arr[i];
            if (nextOcc.find(val) == nextOcc.end())
                pre[i]++;

            nextOcc[val].insert(i);
        }

        for (int i = 1; i < n; i++)
            pre[i] = (pre[i] + pre[i - 1]) % mod;

        LazySegmentTree *lst = new LazySegmentTree(n, pre);

        ll ans = 0;

        for (int l = 0; l < n; l++)
        {
            ll val = arr[l];

            // phele query kar
            ans = (ans + lst->query(0, 0, n - 1, l, n - 1)) % mod;

            // occ remove kar ab
            nextOcc[val].erase(l);

            int r = -1;
            if (!nextOcc[val].empty())
            {
                r = *nextOcc[val].begin();
                r--;
            }

            if (r == -1)
                lst->update(0, 0, n - 1, l, n - 1, mod - 1);
            else
                lst->update(0, 0, n - 1, l, r, mod - 1);
        }

        return ans % mod;
    }
};