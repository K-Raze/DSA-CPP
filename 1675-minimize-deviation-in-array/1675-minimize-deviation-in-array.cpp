class Solution {
public:
    // 3 // inc  
    // 2 2 2 // dec

    int minimumDeviation(vector<int>& arr) {
        for(int& x : arr)
            if(x&1)
                x*=2;
        multiset<int>mst;
        for(int& x : arr)
            mst.insert(x);
        int ans=*max_element(arr.begin(),arr.end())-*min_element(arr.begin(),arr.end());
        while(1)
        {
            int r=*mst.rbegin();
            int l=*mst.begin();
            ans=min(ans,r-l);
            if(r&1)
                break;
            else
            {
                auto it=mst.find(r);
                mst.erase(it);
                r/=2;
                mst.insert(r);
            }
        }
        return ans;
    }
};