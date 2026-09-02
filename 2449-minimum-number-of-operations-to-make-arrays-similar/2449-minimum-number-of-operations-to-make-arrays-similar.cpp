using ll=long long;
class Solution {
public:

    long long makeSimilar(vector<int>& arr1, vector<int>& arr2) {
        vector<int>even1,even2,odd1,odd2;
        for(int x : arr1)
        {
            if(x&1)
                odd1.push_back(x);
            else
                even1.push_back(x);
        }
        for(int x : arr2)
        {
            if(x&1)
                odd2.push_back(x);
            else
                even2.push_back(x);
        }
        sort(even1.begin(),even1.end());
        sort(even2.begin(),even2.end());
        sort(odd1.begin(),odd1.end());
        sort(odd2.begin(),odd2.end());
        ll ans=0;
        for(int i=0;i<even1.size();i++)
            ans+=abs(even1[i]-even2[i]);
        for(int i=0;i<odd1.size();i++)
            ans+=abs(odd1[i]-odd2[i]);
        return ans/4;
    }
};