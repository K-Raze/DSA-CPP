#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;

typedef tree<
    ll,
    null_type,
    less_equal<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

// st.find_by_order(i) give iterator to element at index i 
// st.order_of_key(x) give index to first element that is >=x 
// or it tells number of elements less than x

class Solution {
public:
    int countRangeSum(vector<int>& arr, int lower, int upper) {
        int n=arr.size();
        vector<ll>pre(n);
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+arr[i];
        ordered_multiset poset;
        ll ans=0;

        // pre[i]-lower>=pre[j]
        // pre[i]-upper<=pre[j]
        poset.insert(0);

        for(int i=0;i<n;i++)
        {
            int lft=poset.order_of_key(pre[i]-upper);
            int ryt=poset.order_of_key(pre[i]-lower+1);
            ans+=ryt-lft;
            poset.insert(pre[i]);
        }
        return ans;
    }
};