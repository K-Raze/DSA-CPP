using ll=long long;

class Solution {
public:
    int kthDigit(long long n) {
        vector<ll> meow = {0};
        vector<ll> st = {0};
        {
            ll val9 = 9;
            meow.push_back(9);
            st.push_back(1);
            for (int i = 2; i <= 15; i++)
            {
                val9 *= 10;
                meow.push_back(val9 * i);
                st.push_back(st.back() * 10LL);
            }
        }
        for (int i = 1; i < meow.size(); i++)
            meow[i] += meow[i - 1];
        ll start = 1, end = 1e14;

        while (start <= end)
        {
            ll mid = start + ((end - start) >> 1);
            ll val=mid;
            ll par=((val/10)%10)%2;
            if(par)
            {
                int ld=val%10;
                val-=ld;
                val+=(9-ld);
            }
            ll dig;
            {
                string s = to_string(val);
                dig = s.size();
            }
            ll base = meow[dig - 1];
            base += dig * (mid - st[dig]);
            ll l = base + 1, r = base + dig;
            if (n >= l && n <= r)
            {
                string s = to_string(val);
                n -= l;
                return s[n] - '0';
            }
            else if (n < l)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return 0;
    }
};