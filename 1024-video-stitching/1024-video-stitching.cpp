class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int curr=0; // search from here 
        int i=0;
        int ans=0;
        while(curr<=time-1)
        {
            int mr=curr;
            while(i<clips.size() && clips[i][0]<=curr)
                mr=max(mr,clips[i++][1]);
            if(mr==curr)
                return -1;
            ans++;
            curr=mr;
        }
        return ans;
    }
};