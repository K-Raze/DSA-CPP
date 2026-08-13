class Solution {
public:

    // opa opa quesss
    // hard concept + implementation--------------------:

    // a-b-c-d
    //   |         suppose root is a of this dsu comp
    //   e-f-g  

    // div[g]-> a/g
    // div[d]-> a/d

    // ->ek to queries same comp se honi chaie
    // -> e/d   first compute a/e and a/d , divide them !!

    vector<int>par,sz;
    vector<double>div;

    void init(int n)
    {
        par.resize(n);
        iota(par.begin(),par.end(),0);
        sz.assign(n,1);
        div.assign(n,1.0);
    }

    // root and root/q return krega ye
    pair<int,double> ultPar(int x)
    {
        if(par[x]==x)
            return {x,1};
        auto it=ultPar(par[x]);
        par[x]=it.first;
        div[x]=it.second*div[x]; // r/b * b/c = r/c
        return {par[x],div[x]};
    }

    void unite(int a,int b,double w)
    {
        auto [p1,d1]=ultPar(a);
        auto [p2,d2]=ultPar(b);
        if(p1==p2)
            return;
        if(sz[p1]<sz[p2])
        {
            swap(p1,p2);
            swap(d1,d2);
            w=1.0/w;
        }
        sz[p1]+=sz[p2];
        par[p2]=p1;
        div[p2]=d1*w/d2;
    }

    double query(int a,int b)
    {
        auto [p1,d1]=ultPar(a);
        auto [p2,d2]=ultPar(b);
        if(p1!=p2)
            return -1.0;
        return d2/d1;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string>st;
        for(auto& it : equations)
        {
            st.insert(it[0]);
            st.insert(it[1]);
        }
        int n=st.size();
        unordered_map<string,int>mp; // ye string to idx dedega
        int idx=0;
        for(string s : st)
            mp[s]=idx++;

        init(n);

        for(int i=0;i<values.size();i++)
            unite(mp[equations[i][0]],mp[equations[i][1]],values[i]);
        
        vector<double>ans;
        for(auto& it : queries)
        {
            if(st.find(it[0])==st.end() || st.find(it[1])==st.end())
                ans.push_back(-1.0);
            else
                ans.push_back(query(mp[it[0]],mp[it[1]]));
        }
        return ans;
    }
};