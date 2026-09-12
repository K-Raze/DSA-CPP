#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;

typedef tree<
    pair<ll,int>,
    null_type,
    less<pair<ll,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

// st.find_by_order(i) give iterator to element at index i 
// st.order_of_key(x) give index to first element that is >=x 

class Solution {
public:

    // | pre[r]-pre[l-1]-goal | >=k
    // pre[r]-pre[l-1]-goal >=k
    // pre[r]-pre[l-1]-goal <=-k

    // pre[l-1] <= pre[r]-goal-k
    // pre[l-1] >= pre[r]-goal+k

    long long distantSubarrays(vector<int>& arr, int goal, int k) {
        ll ans=0;

        ordered_multiset pbds;
        pbds.insert({0,0});
        ll pre=0;
        for(int i=0;i<arr.size();i++)
        {
            pre+=arr[i];
            if(k)
            {
                ll val1=pre-goal-k;
                ans+=pbds.order_of_key({val1+1,-1});
                ll val2=pre-goal+k;
                ans+=pbds.size()-pbds.order_of_key({val2,-1});
            }
            else
                ans+=pbds.size();
            pbds.insert({pre,i+1});
        }
        return ans;
    }
};