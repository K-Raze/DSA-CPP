class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k)
        {
            int n=s.size();
            string temp;
            for(int i=0;i<n;i+=k)
            {
                int sum=0;
                for(int j=i;j<min(n,i+k);j++)
                    sum+=s[j]-'0';
                temp+=to_string(sum);
            }
            s=temp;
        }
        return s;
    }
};