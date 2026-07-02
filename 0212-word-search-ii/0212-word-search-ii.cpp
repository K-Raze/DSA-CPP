class Solution {
public:

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

    vector<string>ans;

    int n,m;

    int r[4]={0,0,1,-1};
    int c[4]={1,-1,0,0};

    inline bool isValid(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }

    void dfs(int x,int y,vector<vector<bool>>& vis,node* curr,string& s
        ,vector<vector<char>>& mat)
    {
        if(curr->isEnd)
        {
            ans.push_back(s);
            curr->isEnd=0;
        }

        vis[x][y]=1;

        for(int k=0;k<4;k++)
        {
            int nx=x+r[k];
            int ny=y+c[k];
            if(isValid(nx,ny) && !vis[nx][ny] && curr->child[mat[nx][ny]-'a'])
            {
                s+=mat[nx][ny];
                dfs(nx,ny,vis,curr->child[mat[nx][ny]-'a'],s,mat);
                s.pop_back();
            }
        }
        vis[x][y]=0;
    }

    vector<string> findWords(vector<vector<char>>& mat, vector<string>& words) {
        n=mat.size(),m=mat[0].size();

        node* root = new node();
        for(string& s : words)
            insertDfs(root,0,s);
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            if(root->child[mat[i][j]-'a'])
            {
                string s;
                s+=mat[i][j];
                dfs(i,j,vis,root->child[mat[i][j]-'a'],s,mat);
            }
        return ans;
    }
};