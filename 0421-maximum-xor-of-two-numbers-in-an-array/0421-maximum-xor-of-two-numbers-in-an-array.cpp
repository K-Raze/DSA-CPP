class Solution {
public:

    class node
    {
        public:
            node* child[2];

            node()
            {
                child[0]=NULL;
                child[1]=NULL;
            }
    };

    void insert(node* curr,int num,int bit)
    {
        if(bit<0)
            return;

        int b=(num>>bit)&1;

        if(curr->child[b]==NULL)
            curr->child[b]=new node();

        insert(curr->child[b],num,bit-1);
    }

    int find(node* curr,int num,int bit)
    {
        if(bit<0)
            return 0;

        int b=(num>>bit)&1;

        if(curr->child[1-b])
            return (1<<bit)+find(curr->child[1-b],num,bit-1);

        return find(curr->child[b],num,bit-1);
    }

    int findMaximumXOR(vector<int>& nums)
    {
        node* root=new node();

        for(int &x:nums)
            insert(root,x,31);

        int ans=0;

        for(int &x:nums)
            ans=max(ans,find(root,x,31));

        return ans;
    }
};