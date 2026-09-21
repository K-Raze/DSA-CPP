using ll=long long;
class Solution {
public:
    long long calculateScore(vector<string>& ins, vector<int>& val) {
        ll ans=0;
        int idx=0;
        vector<bool>vis(val.size(),0);
        while(idx>=0 && idx<val.size())
        {
            if(vis[idx])
                break;
            vis[idx]=1;
            if(ins[idx]=="add")
            {
                ans+=val[idx];
                idx++;
            }
            else
                idx+=val[idx];
        }
        return ans;
    }
};