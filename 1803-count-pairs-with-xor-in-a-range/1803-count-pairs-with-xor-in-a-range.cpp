class Solution {
public:

    class Node {
    public:
        Node* child[2];
        int cnt;
        Node() {
            child[0] = child[1] = NULL;
            cnt=0;
        }
    };

    void insert(Node* root, int x) {
        Node* temp = root;

        for(int bit = 30; bit >= 0; bit--)
        {
            int b = (x >> bit) & 1;
            if(temp->child[b] == NULL)
                temp->child[b] = new Node();
            temp = temp->child[b];
            temp->cnt++;
        }
    }

    int countPair(Node* root,int val,int idx,int lim)
    {
        if(idx<0)
            return root->cnt;
        bool bl=((lim>>idx)&1);
        bool bv=((val>>idx)&1);
        int ans=0;
        if(bl)
        {
            // 0 krde xor
            if(root->child[bv])
                ans+=root->child[bv]->cnt;
            if(root->child[1-bv])
                ans+=countPair(root->child[1-bv],val,idx-1,lim);
        }
        else
            if(root->child[bv])
                ans+=countPair(root->child[bv],val,idx-1,lim);
        return ans;
    }

    int countPairs(vector<int>& arr, int low, int high) {
        int ans=0;
        Node* root=new Node();

        for(int& x : arr)
        {
            ans+=countPair(root,x,30,high);
            ans-=countPair(root,x,30,low-1);
            insert(root,x);
        }
        return ans;
    }
};