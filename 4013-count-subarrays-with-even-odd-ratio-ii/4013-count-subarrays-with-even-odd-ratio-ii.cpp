#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;

typedef tree<
    tuple<ll,ll,int>,
    null_type,
    less<tuple<ll,ll,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

// st.find_by_order(i) give iterator to element at index i 
// st.order_of_key(x) give index to first element that is >=x 

// bx<=ay
// b(e[r]-e[l-1])<=a(o[r]-o[l-1])
// be[r]-ao[r]<=be[l-1]-ao[l-1];

// 

class Solution
{
    public:

        long long countRatioSubarrays(vector<int> &arr, int a, int b) {
            int n=arr.size();

            ordered_multiset st;
            st.insert({0,0,0});

            ll even=0,odd=0;
            ll ans=0;

            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]&1)
                    odd++;
                else
                    even++;

                ll val=b*even-a*odd;
                // barabar and bade add krde
                ans+=st.size()-st.order_of_key({val,-2,-2});
                // total odd find kr jo satisfy krre h
                ll temp=st.order_of_key({val,odd+1,-2});
                temp-=st.order_of_key({val,odd,-2});
                ans-=temp;
                st.insert({val,odd,i+1});
            }
            return ans;
        }
};