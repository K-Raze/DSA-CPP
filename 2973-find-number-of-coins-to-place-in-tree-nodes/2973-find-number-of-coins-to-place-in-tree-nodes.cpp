// all pos
// 1 pos 2 neg
using ll = long long;
class Solution {
public:

    vector<vector<int>>adj;
    vector<ll>nodeVal;
    vector<int>subSize;

    vector<ll>ans;

    pair<vector<ll>,vector<ll>> dfs(int x,int par)
    {
        subSize[x]=1;
        multiset<ll>pos,neg;
        if(nodeVal[x]>=0)
            pos.insert(nodeVal[x]);
        else
            neg.insert(nodeVal[x]);
        
        for(int& y : adj[x])
            if(y!=par)
            {
                auto[childPos,childNeg]=dfs(y,x);
                subSize[x]+=subSize[y];
                for(ll val : childPos)
                {
                    if(pos.size()<3)
                        pos.insert(val);
                    else if(pos.size()==3 && *pos.begin()<val)
                    {
                        auto it=pos.begin();
                        pos.erase(it);
                        pos.insert(val);
                    }
                }
                for(ll val : childNeg)
                {
                    if(neg.size()<2)
                        neg.insert(val);
                    else if(neg.size()==2)
                    {
                        auto it=neg.end();
                        it--;
                        if(*it>val)
                        {
                            neg.erase(it);
                            neg.insert(val);
                        }
                    }
                }
            }
        ans[x]=0;
        if(pos.size()==3)
        {
            auto it=pos.begin();
            ll mul=1;
            while(it!=pos.end())
            {
                mul*=(*it);
                it++;
            }
            ans[x]=max(ans[x],mul);
        }
        if(pos.size() && neg.size()==2)
        {
            auto it=pos.end();
            it--;
            ll mul=*it;
            auto it0=neg.begin();
            while(it0!=neg.end())
            {
                mul*=(*it0);
                it0++;
            }
            ans[x]=max(ans[x],mul);
        }
        if(subSize[x]<3)
            ans[x]=max(ans[x],1LL);
        return {vector<ll>(pos.begin(),pos.end()),
                vector<ll>(neg.begin(),neg.end())};
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n=cost.size();
        ans.resize(n);
        adj.resize(n);
        subSize.assign(n,0);
        for(auto& it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        nodeVal.resize(n);
        for(int i=0;i<n;i++)
            nodeVal[i]=cost[i];
        dfs(0,-1);
        return ans;
    }
};