using ll=long long;
class Solution {
public:
    //  sorted | abcdef | sorted 
    // 1 : 2 23 234
    // 12 :3 34
    // 123 : 4
    // 4 : 3 23 123

    // 4 umm complex hora h , divide krde
    // crackedddd


    long long incremovableSubarrayCount(vector<int>& arr) {
        int n=arr.size();

        vector<pair<int,int>>up;
        {
            int idx=1;
            up.push_back({arr[0],0});
            while(idx<arr.size() && arr[idx]>arr[idx-1])
            {
                up.push_back({arr[idx],idx});
                idx++;
            }
            if(up.size()==arr.size())
                up.pop_back();
        }
        vector<pair<int,int>>down;
        {
            int idx=n-2;
            down.push_back({arr.back(),n-1});
            while(idx>=0 && arr[idx]<arr[idx+1])
            {
                down.push_back({arr[idx],idx});
                idx--;
            }
            reverse(down.begin(),down.end());
        }
        for(auto[x,y] : up)
            cout<<x<<" ";
        cout<<endl;
        for(auto[x,y]: down)
            cout<<x<<" ";

        ll ans=0;

        int u=0,d=0;
        while(u<up.size())
        {
            while(d<down.size() && down[d].first<=up[u].first)
                d++;
            if(d==down.size())
                ans++;
            else
            {
                ans+=down.size()-d;
                if(up[u].second+1!=down[d].second)
                    ans++;
            }
            u++;
        }
        return ans+down.size()+(down.front().second>0);
    }
};