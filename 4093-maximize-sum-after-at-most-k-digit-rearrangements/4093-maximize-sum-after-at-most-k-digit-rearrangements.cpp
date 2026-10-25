using ll=long long;
class Solution {
public:

    ll giveMax(int n)
    {
        string s=to_string(n);
        sort(s.rbegin(),s.rend());
        return stoll(s);
    }

    long long maximizeSum(vector<int>& num, int k) {
        int n=num.size();

        vector<pair<ll,ll>>arr(n);
        for(int i=0;i<n;i++)
            arr[i]={giveMax(num[i]),num[i]};
        sort(arr.begin(),arr.end(),[&](const auto& a,const auto& b){
            return a.first-a.second>b.first-b.second;
        });
        // for(int i=0;i<n;i++)
        //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
        ll ans=0;
        for(int i=0;i<k;i++)
            ans+=arr[i].first;
        for(int i=k;i<n;i++)
            ans+=arr[i].second;
        return ans;
    }
};