class Solution
{
    public:

        struct node
        {
            int maxVal;
            int freqLeft;
            int freqRight;
            char chLeft;
            char chRight;
            int len;
        };

       	// ============== NORMAL SEGMENT TREE ===============
        class SegmentTree
        {
            public:
            int n;
            vector<node> seg;

            node merge(const node& a,const node& b)
            {
                node ans;
                ans.chLeft=a.chLeft;
                ans.chRight=b.chRight;
                ans.len=a.len+b.len;

                if(a.freqLeft==a.len) // left all same char
                {
                    if(a.chRight==b.chLeft)
                        ans.freqLeft=a.len+b.freqLeft;
                    else
                        ans.freqLeft=a.len;
                }
                else
                    ans.freqLeft=a.freqLeft;

                if(b.freqLeft==b.len) // right all same char
                {
                    if(a.chRight==b.chLeft)
                        ans.freqRight=b.len+a.freqRight;
                    else
                        ans.freqRight=b.len;
                }
                else
                    ans.freqRight=b.freqRight;

                ans.maxVal=max(a.maxVal,b.maxVal);
                if(a.chRight==b.chLeft)
                    ans.maxVal=max(ans.maxVal,a.freqRight+b.freqLeft);
                return ans;
            }

            SegmentTree(int n, string& s)
            {
                this->n = n;
                seg.resize(4 *n);
                build(0, 0, n - 1, s);
            }

            void build(int i, int l, int r, string& s)
            {
                if (l == r)
                {
                    seg[i] = {1,1,1,s[l],s[l],1};
                    return;
                }
                int mid = l + ((r - l) >> 1);
                build(2 *i + 1, l, mid, s);
                build(2 *i + 2, mid + 1, r, s);
                seg[i] = merge(seg[2 *i + 1] , seg[2 *i + 2]);
            }

            void pointUpdate(int i, int l, int r, int idx, char ch)
            {
                if (l == r)
                {
                    seg[i] = {1,1,1,ch,ch,1};
                    return;
                }
                int mid = l + ((r - l) >> 1);
                if (idx <= mid)
                    pointUpdate(2 *i + 1, l, mid, idx, ch);
                else
                    pointUpdate(2 *i + 2, mid + 1, r, idx, ch);
                seg[i] = merge(seg[2 *i + 1] , seg[2 *i + 2]);
            }
        };
   	// --------------------------------------------------

    vector<int> longestRepeating(string s, string qc, vector<int> &qi)
    {
        int n=s.size();
        SegmentTree*st =new SegmentTree(n,s);
        vector<int>ans;
        for(int i=0;i<qc.size();i++)
        {
            st->pointUpdate(0,0,n-1,qi[i],qc[i]);
            ans.push_back(st->seg[0].maxVal);
        }
        return ans;
    }
};