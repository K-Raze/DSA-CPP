class Solution {
public:

    // l>=r-l
    // r<=2l

    // 1 2 3 4 5
    // 001 010 011 100 101


    class node
    {
        public : 
        node* child[2];
        int cnt;
        node()
        {
            child[0]=child[1]=NULL;
            cnt=0;
        }
    };

    void insert(node* curr,int bit,int val)
    {
        curr->cnt++;
        if(bit==-1)
            return;
        bool path=((val>>bit)&1);
        if(!curr->child[path])
            curr->child[path]=new node();
        insert(curr->child[path],bit-1,val);
    }

    void rem(node* curr,int bit,int val)
    {
        if(curr->cnt)
            curr->cnt--;
        if(bit==-1)
            return;
        bool path=((val>>bit)&1);
        rem(curr->child[path],bit-1,val);
    }

    int query(node* curr,int bit,int val)
    {
        if(bit==-1)
            return 0;
        bool path=!((val>>bit)&1);
        int ans=0;
        if(curr->child[path] && curr->child[path]->cnt)
            ans+=(1<<bit);
        else
            path=1-path;
        ans+=query(curr->child[path],bit-1,val);
        return ans;
    }


    int maximumStrongPairXor(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        node* root=new node();

        int l=0;
        int ans=0;
        for(int r=0;r<n;r++)
        {
            insert(root,30,arr[r]);
            while(arr[r]>2*arr[l])
            {
                rem(root,30,arr[l]);
                l++;
            }
            ans=max(ans,query(root,30,arr[r]));
        }
        return ans;
    }
};