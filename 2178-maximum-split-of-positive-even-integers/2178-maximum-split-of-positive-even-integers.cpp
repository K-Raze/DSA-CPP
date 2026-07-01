using ll=long long;
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum&1)
            return {};
        ll val=2;
        ll sum=0;
        while(sum+val<=finalSum)
        {
            sum+=val;
            val+=2;
        }
        vector<ll>ans;
        for(int i=2;i<val;i+=2)
            ans.push_back(i);
        ans[ans.size()-1]+=finalSum-sum;
        return ans;
    }
};