class Solution {
public:

    // w >= c
    // w+= p-c;
    // p>c !! 

    // i want 2 sorting orders 
    // first is c 
    // another is p-c
    // ig its 2 pointer + pq

    // 0 1 1
    // 1 1 2 

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n=profits.size();

        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++)
            arr[i]={capital[i],profits[i]};
        
        sort(arr.begin(),arr.end());
        int ptr=0;
        priority_queue<int>pq;
        while(k)
        {
            while(ptr<n && arr[ptr].first<=w)
                pq.push(arr[ptr++].second);
            if(!pq.empty() && pq.top()>0)
            {
                k--;
                w+=pq.top();
                pq.pop();
            }
            else 
                break;
        }
        return w;
    }
};