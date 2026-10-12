
// make trie 
// each node return array<int,10>cnt of 10 numnbers.
// sort them using custom comp for minimum inversions 
// upar return krde

class Solution {
public:

    class Node
    {
        public : 
        int isEnd;
        Node* child[10];
        Node()
        {
            isEnd=-1;
            for(int i=0;i<10;i++)
                child[i]=NULL;
        }
    };

    
    void insert(Node* curr,int x,string& s,int val)
    {
        if(x==s.size())
        {
            curr->isEnd=val;
            return;
        }
        int idx=s[x]-'a';
        if(!curr->child[idx])
            curr->child[idx]=new Node();
        insert(curr->child[idx],x+1,s,val);
    }

    int ans;

    inline int inv(const auto& a,const auto& b)
    {
        int u=0,d=0;
        int cnt=0;
        while(u<a.size())
        {
            while(d<b.size() && a[u]>b[d])
                d++;
            cnt+=d;
            u++;
        }
        return cnt;
    }
    // 2^10 * (1e4) * 
    inline void merge(auto& a,const auto& b)
    {
        int l=0,r=0;
        vector<int>temp;
        while(l<a.size() && r<b.size())
        {
            if(a[l]<b[r])
                temp.push_back(a[l++]);
            else
                temp.push_back(b[r++]);
        }
        while(l<a.size())
            temp.push_back(a[l++]);
        while(r<b.size())
            temp.push_back(b[r++]);
        a=move(temp);
    }

    int solve(int mask,vector<vector<int>>& pairInv,int m,
            vector<int>& dp)
    {
        if(dp[mask]!=-1)
            return dp[mask];
        if( mask == ( 1<<m )-1 )
            return 0;
        int ans=2e9;
        for(int ni=0;ni<m;ni++)
            if(!((mask>>ni)&1))
            {
                int meow=0;
                for(int i=0;i<m;i++)
                    if(((mask>>i)&1))
                        meow+=pairInv[i][ni];
                ans=min(ans,meow+solve((mask | (1<<ni)),pairInv,m,dp));
            }
        return dp[mask]=ans;
    }
    
    vector<int> dfs(Node* curr)
    {
        vector<int>temp;
        if(curr->isEnd!=-1)
            temp.push_back(curr->isEnd);
        vector<vector<int>>arr;
        for(int i=0;i<10;i++)
            if(curr->child[i])
                arr.push_back(dfs(curr->child[i]));

        // sort(arr.begin(),arr.end(),[&](const auto& a,const auto& b)
        //      {
        //          return inv(a,b)<inv(b,a);
        //      });

        int m=arr.size();
        if(m>1)
        {
            vector<vector<int>>pairInv(m,vector<int>(m,0));
            for(int i=0;i<m;i++)
                for(int j=0;j<m;j++)
                    if(i!=j)
                        pairInv[i][j]=inv(arr[i],arr[j]);
            vector<int>dp(1<<m,-1);
            ans+=solve(0,pairInv,m,dp);
        }

        
        for(int i=0;i<arr.size();i++)
            ans+=inv(temp,arr[i]);
        for(int i=0;i<arr.size();i++)
            merge(temp,arr[i]);
        return temp;
    }
    
    int minInversions(vector<string>& words, vector<int>& target) {
        int n=words.size();

        unordered_map<int,int>mpIdx;
        for(int i=0;i<n;i++)
            mpIdx[target[i]]=i;
        
        Node* root=new Node();
        for(int i=0;i<words.size();i++)
                insert(root,0,words[i],mpIdx[i]);
        
        ans=0;
        dfs(root);
        return ans;
    }
};