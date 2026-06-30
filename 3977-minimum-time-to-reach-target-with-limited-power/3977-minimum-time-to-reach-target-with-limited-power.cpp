using ll=long long;
const ll inf=4e18;
class Solution {
public:

    // can i reach to the target ? 
    // minimum time to reach the target
    // maximum energy remain 

    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& it : edges)
            adj[it[0]].push_back({it[1],it[2]});


        auto cmp=[](const array<ll,3>& a,const array<ll,3>& b)
        {
            if(a[0]!=b[0])
                return a[0]>b[0];
            return a[1]<b[1];
        };
        priority_queue<array<ll,3>,vector<array<ll,3>>,decltype(cmp)>pq(cmp); 

        vector<vector<ll>>time(n,vector<ll>(power+1,inf));
        pq.push({0,power,source});
        time[source][power]=0;

        while(!pq.empty())
        {
            auto[t,p,x]=pq.top();
            pq.pop();

            if(t!=time[x][p])
                continue;

            if(x==target)
                return {t,p};

            if(p<cost[x])
                continue;

            for(auto&[y,dt] : adj[x])
                if(t+dt<time[y][p-cost[x]])
                {
                    time[y][p-cost[x]]=t+dt;
                    pq.push({t+dt,p-cost[x],y});
                }
        }

        return {-1,-1};
    }
};