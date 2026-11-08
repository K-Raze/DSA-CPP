
class Solution {
public:
    int countServers(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int>row(n,0),col(m,0);

        // row check
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j])
                    row[i]++;
        
        // col check
        for(int j=0;j<m;j++)
            for(int i=0;i<n;i++)
                if(mat[i][j])
                    col[j]++;
        
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j] && (row[i]>1 || col[j]>1))
                    ans++;
        
        return ans;
    }
};