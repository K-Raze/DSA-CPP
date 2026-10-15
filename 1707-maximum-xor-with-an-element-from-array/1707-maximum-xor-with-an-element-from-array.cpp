class Solution {
public:

    class node
    {
        public : 
        node* child[2];
        node()
        {
            child[0]=child[1]=NULL;
        }
    };

    void insert(node* curr,int bit,int val)
    {
        if(bit==-1)
            return;
        bool path=((val>>bit)&1);
        if(!curr->child[path])
            curr->child[path]=new node();
        insert(curr->child[path],bit-1,val);
    }

    int query(node* curr,int bit,int val)
    {
        if(bit==-1)
            return 0;
        bool path=!((val>>bit)&1);
        int ans=0;
        if(curr->child[path])
            ans+=(1<<bit);
        else
            path=1-path;
        ans+=query(curr->child[path],bit-1,val);
        return ans;
    }

    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        int qn=queries.size();
        for(int i=0;i<qn;i++)
            queries[i].push_back(i);
        sort(arr.begin(),arr.end());
        sort(queries.begin(),queries.end(),[&](const auto& a,const auto& b){
            return a[1]<b[1];
        });
        vector<int>ans(qn);

        node* root=new node();

        int ptr=0;

        for(auto& it : queries)
        {
            int x=it[0],m=it[1],idx=it[2];
            while(ptr<arr.size() && arr[ptr]<=m)
            {
                insert(root,30,arr[ptr]);
                ptr++;
            }
            if(!ptr)
                ans[idx]=-1;
            else
                ans[idx]=query(root,30,x);
        }
        return ans;
    }   
};