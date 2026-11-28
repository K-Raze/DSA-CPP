class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {

        int n=mat.size(),m=mat[0].size();

        vector<array<int,3>>arr;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                arr.push_back({mat[i][j],i,j});
        sort(arr.rbegin(),arr.rend());

        vector<int>rowMax(n,0),colMax(m,0);

        int l=0;
        while(l<arr.size())
        {
            int r=l;
            while(r<arr.size() && arr[r][0]==arr[l][0])
                r++;
            
            map<pair<int,int>,int>temp;
            for(int i=l;i<r;i++)
            {
                int x=arr[i][1],y=arr[i][2];
                if(temp.find({x,y})==temp.end())
                    temp[{x,y}]=1+max(rowMax[x],colMax[y]);
                else
                    temp[{x,y}]=max(temp[{x,y}],1+max(rowMax[x],colMax[y]));
            }

            for(auto&[pr,val] : temp)
            {
                int x=pr.first,y=pr.second;
                rowMax[x]=max(rowMax[x],val);
                colMax[y]=max(colMax[y],val);
            }

            l=r;
        }
        return max(*max_element(rowMax.begin(),rowMax.end()),
            *max_element(colMax.begin(),colMax.end())
                );
    }
};