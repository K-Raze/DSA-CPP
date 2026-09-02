class Solution {
public:
    string largestNumber(vector<int>& num) {
        vector<string>arr;
        for(int& x : num)
            arr.push_back(to_string(x));
        sort(arr.begin(),arr.end(),[&](const string& s1,const string& s2){
            return s1+s2>s2+s1;
        });
        string ans;
        for(string& s : arr)
            ans+=s;
        if(ans.front()=='0')
            return "0";
        return ans;
    }
};