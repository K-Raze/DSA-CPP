class node
{
    public:
        bool isEnd;
        node* child[26];
        node()
        {
            isEnd=0;
            for(int i=0;i<26;i++)
                child[i]=NULL;
        }
};

class Trie {
public:

    node* root;

    Trie() {
        root=new node();
    }

    void insertDfs(node* curr,int idx,string& word)
    {
        if(idx==word.size())
        {
            curr->isEnd=1;
            return;
        }
        int nextIdx=word[idx]-'a';
        if(curr->child[nextIdx])
            insertDfs(curr->child[nextIdx],idx+1,word);
        else
        {
            curr->child[nextIdx]=new node();
            insertDfs(curr->child[nextIdx],idx+1,word);
        }
    }

    void insert(string word) {
        insertDfs(root,0,word);
    }

    bool searchDfs(node* curr,int idx,string& word)
    {
        if(idx==word.size())
            return curr->isEnd;
        int nextIdx=word[idx]-'a';
        if(curr->child[nextIdx])
            return searchDfs(curr->child[nextIdx],idx+1,word);
        return 0;
    }

    bool search(string word) {
        return searchDfs(root,0,word);
    }
    
    bool preDfs(node* curr,int idx,string& word)
    {
        if(idx==word.size())
            return 1;
        int nextIdx=word[idx]-'a';
        if(curr->child[nextIdx])
            return preDfs(curr->child[nextIdx],idx+1,word);
        return 0;
    }

    bool startsWith(string prefix) {
        return preDfs(root,0,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */