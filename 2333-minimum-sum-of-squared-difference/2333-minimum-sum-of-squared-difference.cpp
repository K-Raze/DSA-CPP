using ll=long long;
class Solution {
public:

    // 1 4 10 12
    // 5 8 6 9
    // -4 -4 4 3 
    // 3 4 3 3 

    long long minSumSquareDiff(vector<int>& arr1, vector<int>& arr2, int k1, int k2) {
        ll k=k1+k2;
        int n=arr1.size();
        map<ll,ll>mp;
        ll ans=0;
        for(int i=0;i<n;i++)
            if(abs(arr1[i]-arr2[i]))
            {
                mp[abs(arr1[i]-arr2[i])]++;
                ans+=1LL*(arr1[i]-arr2[i])*(arr1[i]-arr2[i]);
            }

        if(mp.empty())
            return 0;
        auto it=mp.end();
        it--;

        while(k)
        {
            ll val=it->first,freq=it->second;
            ans-=val*val*freq;
            ll prev=0;
            if(it!=mp.begin())
            {
                it--;
                prev=it->first;
            }
            // cout<<val<<" "<<freq<<" "<<prev<<endl;

            ll req=freq*(val-prev);
            if(req<=k)
            {
                ans+=freq*prev*prev;
                k-=req;
                if(prev)
                    it->second+=freq;
                else
                    break;
            }
            else
            {
                ll minus=k/freq;
                ll rem=k%freq;
                ans+=rem*(val-minus-1)*(val-minus-1)+
                    (freq-rem)*(val-minus)*(val-minus);
                break;
            }
        }
        return ans;
    }
};