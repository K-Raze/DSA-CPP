using ll = long long;
const ll inf = 4e18;

class Solution {
public:

    ll ans;

    pair<ll,ll> solve(int x, int par, vector<int>& value, vector<vector<pair<int,ll>>>& adj)
    {
        bool valOdd=(__builtin_popcount(value[x])&1);

        vector<pair<ll,ll>>arr;

        for(auto& [y, wt]:adj[x])
            if(y!=par)
            {
                auto[o, e]=solve(y,x,value,adj);
                arr.push_back({wt+o,wt+e});
            }

        if(arr.size()>1)
        {
            ll oddMin=arr[0].first;
            ll evenMin=arr[0].second;

            for(int i=1;i<arr.size();i++)
            {
                ll currOdd=arr[i].first;
                ll currEven=arr[i].second;

                if(valOdd)
                {
                    ans = min(ans,currOdd+evenMin);
                    ans = min(ans,currEven+oddMin);
                }
                else
                {
                    ans = min(ans,currOdd+oddMin);
                    ans = min(ans,currEven+evenMin);
                }

                oddMin = min(oddMin,currOdd);
                evenMin = min(evenMin,currEven);
            }

            if(valOdd)
                ans = min(ans, oddMin);
            else
                ans = min(ans, evenMin);
        }
        else if(arr.size() == 1)
        {
            if(valOdd)
                ans = min(ans,arr[0].first);
            else
                ans = min(ans,arr[0].second);
        }

        pair<ll,ll>ret={inf, inf};

        if(valOdd)
            ret.first=0;
        else
            ret.second=0;

        for(auto [o, e] : arr)
        {
            if(valOdd) 
                swap(o, e);
            ret.first = min(ret.first,o);
            ret.second = min(ret.second,e);
        }
        return ret;
    }

    int minActivationCost(vector<vector<int>>& edges, vector<int>& value)
    {
        ans = inf;
        int n=value.size();

        vector<vector<pair<int,ll>>>adj(n);
        for(auto& it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        solve(0,-1,value,adj);
        if(ans==inf)
            return -1;
        return ans;
    }
};