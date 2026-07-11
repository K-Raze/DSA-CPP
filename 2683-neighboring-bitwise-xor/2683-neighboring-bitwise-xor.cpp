class Solution {
public:
    bool doesValidArrayExist(vector<int>& arr) {
        int n=arr.size();
        // start with 0
        {
            int val=0;
            for(int i=0;i<n;i++)
                if(arr[i]==1)
                    val=1-val;
            if(val==0)
                return 1;
        }
        // start with 1
        {
            int val=1;
            for(int i=0;i<n;i++)
                if(arr[i]==1)
                    val=1-val;
            if(val==1)
                return 1;
        }
        return 0;
    }
};