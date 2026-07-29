class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans=0;
        if(startPos[0]>homePos[0])
        {
            swap(startPos[0],homePos[0]);
            ans+=rowCosts[startPos[0]]-rowCosts[homePos[0]];
        }
        if(startPos[1]>homePos[1])
        {
            swap(startPos[1],homePos[1]);
            ans+=colCosts[startPos[1]]-colCosts[homePos[1]];
        }
        for(int r=startPos[0]+1;r<=homePos[0];r++)
            ans+=rowCosts[r];
        for(int c=startPos[1]+1;c<=homePos[1];c++)
            ans+=colCosts[c];
        return ans;
    }
};