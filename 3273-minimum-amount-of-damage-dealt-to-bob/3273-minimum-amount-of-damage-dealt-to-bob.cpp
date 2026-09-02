using ll=long long;
class Solution {
public:

    // damage jada dera h and health jiski kam ho use marna is ideal
    // health chod hit dekh ceil krke
    // 1 2 3 4 
    // 1 2 2 2
    // a b  
    // h1 h2 
    // h1(a+b)+h2b , h2(a+b)+h1a
    // h1a+h1b+h2b , h2a+h2b+h1a
    // h1b , h2a
    // um i wud have to generalize more 
    // a b c 
    // h1 h2 h3
    // 
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        for(int& x : health)
            x=(x+power-1)/power;
        int n=damage.size();
        vector<pair<ll,ll>>arr(n);
        for(int i=0;i<n;i++)
            arr[i]={damage[i],health[i]};
        sort(arr.begin(),arr.end(),[&](const auto& p1,const auto& p2){
            auto&[a,h1]=p1;
            auto&[b,h2]=p2;
            return a*h2>b*h1;
        });
        ll ans=0;
        ll td=accumulate(damage.begin(),damage.end(),0LL);
        for(auto&[d,h] : arr)
        {
            // cout<<d<<" ";
            ans+=h*td;
            td-=d;
        }
        return ans;
    }
};