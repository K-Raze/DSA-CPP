using ll=long long;
set<ll>even,odd;

    void init()
    {
        if(!even.empty())
            return;
        for(int i=0;i<=2e5;i++)
        {
            string s=to_string(i);
            // stretch 
            {
                string t=s;
                reverse(t.begin(),t.end());
                ll num=stoll(s+t);
                if(num&1)   
                    odd.insert(num);
                else
                    even.insert(num);
            }
            // leave
            {
                string t=s;
                t.pop_back();
                reverse(t.begin(),t.end());
                ll num=stoll(s+t);
                if(num&1)   
                    odd.insert(num);
                else
                    even.insert(num);
            }
        }
    }
class Solution {
public:

    long long minOperations(vector<int>& arr) {
        init();
        ll ans=0;
        for(int& x : arr)
        {
            if(x&1)
            {
                auto it=odd.upper_bound(x);
                ll v1=abs(*it-x)/2;
                if(it==odd.begin())
                    ans+=v1;
                else
                {
                    it--;
                    ans+=min(v1,abs(*it-x)/2);
                }
            }
            else
            {
                auto it=even.upper_bound(x);
                ll v1=abs(*it-x)/2;
                if(it==even.begin())
                    ans+=v1;
                else
                {
                    it--;
                    ans+=min(v1,abs(*it-x)/2);
                }   
            }
        }
        return ans;
    }
};