class Solution {
public:
    string shiftingLetters(string s, vector<int>& arr) {
        int n=s.size();
        for(int i=n-2;i>=0;i--)
        {
            arr[i]+=arr[i+1];
            arr[i]%=26;
        }
        
        for(int i=0;i<n;i++)
        {
            int val=s[i]-'a';
            val+=arr[i];
            val%=26;
            s[i]=val+'a';
        }
        return s;
    }
};