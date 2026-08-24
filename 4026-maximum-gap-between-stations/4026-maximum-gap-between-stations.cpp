class Solution {
public:

    // 1 tu first kidhr lga skta  
    // 2 tu last kha lga skta h inka diff lena h
    
    int maximumGap(string skill, string station) {
        int n=skill.size(),m=station.size();
        if(n==1)
            return 0;
        
        vector<int>last(n+1,-1);
        {
            int val=n;
            int u=n-1;
            for(int d=m-1;d>=0 && u>=0;d--)
                {
                    if(skill[u]==station[d])
                    {
                        last[val]=d;
                        val--;
                        u--;
                    }
                }
        }

        vector<int>first(n+1,-1);
        {
            int val=1;
            int u=0;
            for(int d=0;d<m && u<n;d++)
                {
                    if(skill[u]==station[d])
                    {
                        first[val]=d;
                        val++;
                        u++;
                    }
                }
        }
        int ans=0;
        for(int i=1;i<=n-1;i++)
            ans=max(last[i+1]-first[i],ans);
        return ans;
    }
};