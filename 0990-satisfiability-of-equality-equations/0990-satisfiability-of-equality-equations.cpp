class Solution {
public:

    vector<int>par;

    void dsuInit(int n)
    {
        par.resize(n);
        for(int i=0;i<n;i++)
            par[i]=i;
    }

    int findPar(int x)
    {
        if(x==par[x])
            return x;
        return par[x]=findPar(par[x]);
    }

    void unite(int x,int y)
    {
        x=findPar(x);
        y=findPar(y);
        if(x!=y)
            par[x]=y;
    }

    bool equationsPossible(vector<string>& eq) {
        dsuInit(26);
        for(string& s : eq)
            if(s[1]=='=' && s[2]=='=')
                unite(s[0]-'a',s[3]-'a');
        for(string& s : eq)
            if(s[1]=='!' && s[2]=='=')
                if(findPar(s[0]-'a')==findPar(s[3]-'a'))
                    return 0;
        return 1;
    }
};