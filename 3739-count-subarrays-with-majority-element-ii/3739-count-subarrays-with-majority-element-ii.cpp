// ab uk the pattern , subarray walo me prefix bna logic ke acc
// jese isme take target as +1 and other as -1 
// +ve means that subarray from l to i have target as majority
// segment -> majority rkh 
// l fix kar , then ryt jate jate uska contribution hata segment
// wagera se and contri count krle 

// g faad segment app
// dekh let lazy val=x;
// if maxOfSeg+x<=0 all range contri=0;
// if minOfSeg+x>0 all range contri=len;
// else call left and ryt

// upper approach is overkill
// contribution till end is same throughout of all element
// simple find num of pairs in pref arr ,, such that
// i<j and pre[i]<pre[j] .. segment se krle ya pbds se 
// upper approach is useful if and only if contribution is not same till end
// here if a target give +1 then it is +1 in pref array till the end
// and vice versa for not target element

// bcccc simpleee pbds ka tha :) , upar wali app also correct dw
// pbds because contribution is stable throughout the end 
// if +1 hua h prefix m to end tk contri jayegi
// distinct ke case wali backchodi ni hogi


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

using ll=long long;
class Solution {
public:

    long long countMajoritySubarrays(vector<int>& arr, int tar) {
        int n=arr.size();
        vector<ll>pre(n,0);
        for(int i=0;i<n;i++)
            pre[i]+=(arr[i]==tar) ? 1 : -1;
        for(int i=1;i<n;i++)
            pre[i]+=pre[i-1];
        ordered_multiset pbds;
        pbds.insert(0);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=pbds.order_of_key(pre[i]);
            pbds.insert(pre[i]);
        }
        return ans;
    }
};