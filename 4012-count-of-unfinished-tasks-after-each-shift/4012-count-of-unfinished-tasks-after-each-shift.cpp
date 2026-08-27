using ll=long long;
class Solution {
public:

    // 0 1 5 9
    // 0 2 5 9

    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size(),m=shifts.size();
        {
            reverse(tasks.begin(),tasks.end());
            tasks.push_back(0);
            reverse(tasks.begin(),tasks.end());
        }
        n++;
        vector<ll>pre(n);
        for(int i=0;i<n;i++)
            pre[i]=tasks[i];
        for(int i=1;i<n;i++)
            pre[i]+=pre[i-1];
        
        ll curr=0; 
        vector<int>ans(m);
        for(int i=0;i<m;i++)
        {
            curr+=shifts[i];
            // cout<<curr<<" ";
            int idx=upper_bound(pre.begin(),pre.end(),curr)-pre.begin()-1;
            // cout<<idx<<endl;
            ans[i]=n-idx-1;
            if(idx==n-1)  
                curr=0;
        }
        return ans;
    }
};