class WordDictionary {
public:

    class node
    {
    public:
        bool isEnd;
        node* child[26];

        node()
        {
            isEnd = 0;
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    node* root;

    WordDictionary()
    {
        root = new node();
    }

    void insert(node* curr, int idx, string &word)
    {
        if(idx == word.size())
        {
            curr->isEnd = 1;
            return;
        }

        int nxt = word[idx] - 'a';

        if(curr->child[nxt] == NULL)
            curr->child[nxt] = new node();

        insert(curr->child[nxt], idx + 1, word);
    }

    void addWord(string word)
    {
        insert(root, 0, word);
    }

    bool find(node* curr, int idx, string &word)
    {
        if(curr == NULL)
            return 0;

        if(idx == word.size())
            return curr->isEnd;

        if(word[idx] == '.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(find(curr->child[i], idx + 1, word))
                    return 1;
            }
            return 0;
        }

        int nxt = word[idx] - 'a';

        return find(curr->child[nxt], idx + 1, word);
    }

    bool search(string word)
    {
        return find(root, 0, word);
    }
};