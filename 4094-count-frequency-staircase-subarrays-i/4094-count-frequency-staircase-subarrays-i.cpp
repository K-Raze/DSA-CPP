class Solution {
public:
    int countStaircase(vector<int>& arr) {
        int n=arr.size();

        int ans=0;

        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>num;
            unordered_map<int,int>cnt;
            int as=1;
            int under=0;
            for(int j=i;j<n;j++)
            {
                int val=arr[j];
                cnt[val]++;
                if(num.find(val)==num.end())
                {
                    under++;
                    num[val]=as++;
                }
                if(cnt[val]==num[val])
                    under--;
                else if(cnt[val]>num[val])
                    break;
                if(!under)
                    ans++;
            }
        }

        return ans;

    }
};