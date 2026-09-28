class Solution {
public:
    int maxDepth(string str) {
        int ans=0;
        int bal=0;
        for(char& ch : str)
        {
            if(ch=='(')
            {
                bal++;
                ans=max(ans,bal);
            }
            else if(ch==')')
                bal--;
        }
        return ans;
    }
};