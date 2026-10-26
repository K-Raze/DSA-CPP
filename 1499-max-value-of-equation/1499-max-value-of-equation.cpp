// i fix kr and j>i so xj > xi
//  val = yi-xi + (xj+yj) 

// xj-xi<=k
// xj<=k+xi

const int inf=2e9,ninf=-2e9;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& arr, int k) {
        int ans=INT_MIN;

        int n=arr.size();
        multiset<int>st;
        int j=0;
        for(int i=0;i<n;i++)
        {

            int xi=arr[i][0],yi=arr[i][1];

            while(j<n)
            {
                int xj=arr[j][0],yj=arr[j][1];
                if(xj>k+xi)
                    break;
                st.insert(xj+yj);
                j++;
            }
            // curr remove kr
            auto it=st.find(xi+yi);
            st.erase(it);
            if(!st.empty())
            {
                auto it=st.end();
                it--;
                int val=*it;
                val+=yi-xi;
                ans=max(ans,val);
            }
        }
        return ans;
    }
};