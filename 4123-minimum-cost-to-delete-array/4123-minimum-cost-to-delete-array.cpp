// a b c e f
// 
using ll=long long;
class Solution {
public:
    long long minCost(vector<int>& arr) {
        ll ans=arr.front()+arr.back();

        priority_queue<ll,vector<ll>,greater<ll>>pq;

        for(int i=1;i<arr.size()-1;i++)
            pq.push(arr[i]);
        
        while(pq.size()>1)
        {
            ll temp=pq.top();
            pq.pop();
            temp+=pq.top();
            pq.pop();
            if(temp<0)
                ans+=temp;
            else
                break;
        }
        return ans;
    }
};