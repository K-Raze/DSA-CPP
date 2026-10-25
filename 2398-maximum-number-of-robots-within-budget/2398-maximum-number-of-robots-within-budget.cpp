using ll=long long;
class Solution {
public:

    // postMortem -:
    // max(chargeTimes) + k * sum(runningCosts) <=budget for k robots
    // if we extend k , maxCharge time inc , k inc , sum inc
    // monotinicty-: if 5 robots le skta h to 4 to obv le skta
    // so big k pe check kr
    // bs on ans (k);
    // max maintain sliding window by deque,
    // code krde ab alas mt kr :(

    bool check(int k,vector<int>& cTime, vector<int>& rCost, ll budget)
    {
        deque<int>dq;
        ll sum=0;
        for(int i=0;i<cTime.size();i++)
        {
            if(i<=k-1)
            {
                sum+=rCost[i];
                while(!dq.empty() && cTime[dq.back()]<cTime[i])
                    dq.pop_back();
                dq.push_back(i);
                if(i==k-1)
                {
                    ll cost=cTime[dq.front()]+1LL*k*sum;
                    if(cost<=budget)
                        return 1;
                }
                continue;
            }
            int l=i-k;
            sum-=rCost[l];
            if(dq.front()==l)
                dq.pop_front();
            sum+=rCost[i];
            while(!dq.empty() && cTime[dq.back()]<cTime[i])
                dq.pop_back();
            dq.push_back(i);
            ll cost=cTime[dq.front()]+1LL*k*sum;
            if(cost<=budget)
                return 1;
        }
        return 0;
    }

    int maximumRobots(vector<int>& cTime, vector<int>& rCost, long long budget) {
        int start=1,end=cTime.size();
        while(start<=end)
        {
            int mid=start+((end-start)>>1);
            // can we take mid number of robots
            if(check(mid,cTime,rCost,budget))
                start=mid+1;
            else
                end=mid-1;
        }
        return end;
    }
};