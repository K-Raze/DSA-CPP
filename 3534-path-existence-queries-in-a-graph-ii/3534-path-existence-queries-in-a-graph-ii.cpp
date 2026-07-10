class Solution {
public:
    // vertexMap->
    // (0,1),(1,8),(2,3),(3,4),(4,2); -> (vertex,val)
    // (0,1),(4,2),(2,3),(3,4),(1,8)
    // 0 1 2 3 4 5
    // 1 2 3 4 8
    // 0-2-4 // return
    // 2jump 
    // 
    
    // logn logn->bs

    vector<int> pathExistenceQueries(int n, vector<int>& arr, int maxDiff, vector<vector<int>>& queries) {
        // arr transform
        vector<int>vertexMap(n);
        {
            vector<pair<int,int>>temp(n);
            for(int i=0;i<n;i++)
                temp[i]={arr[i],i};
            sort(temp.begin(),temp.end());
            for(int i=0;i<n;i++)
            {
                vertexMap[temp[i].second]=i;
                arr[i]=temp[i].first;
            }
        }

        vector<vector<int>>binaryPar(n,vector<int>(21,-1));
        for(int i=0;i<n;i++)
        {
            int idx=upper_bound(arr.begin(),arr.end(),arr[i]+maxDiff)-arr.begin()-1;
            binaryPar[i][0]=idx;
        }
        for(int p=1;p<=20;p++)
            for(int i=0;i<n;i++)
            {
                int pp=binaryPar[i][p-1];
                if(pp==-1)
                    continue;
                binaryPar[i][p]=binaryPar[pp][p-1];
            }
        
        vector<int>ans;
        for(auto& it : queries)
        {
            int u=vertexMap[it[0]];
            int v=vertexMap[it[1]];
            if(u==v)
            {
                ans.push_back(0);
                continue;
            }
            if(arr[u]>arr[v])
                swap(u,v);
            int jump=0;
            for(int p=20;p>=0;p--)
                if(binaryPar[u][p]<v)
                {
                    u=binaryPar[u][p];
                    jump+=(1<<p);
                }

            u = binaryPar[u][0];
            jump++;

            if(jump<n)
                ans.push_back(jump);
            else
                ans.push_back(-1);
        }
        return ans;

    }
};