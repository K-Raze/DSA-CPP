class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        
        int start=1,end=s.size();
        vector<int>ans;
        while(start<=end)
        {
            int mid=start+((end-start)>>1);
            // check
            vector<int>temp(s.size(),0);
            bool good=1;
            int b1=0,b2=0;
            int idx=0;
            for(char& ch : s)
            {
                if(ch=='(')
                {
                    if(b1<mid)
                    {
                        b1++;
                        temp[idx]=0;
                    }
                    else if(b2<mid)
                    {
                        b2++;
                        temp[idx]=1;
                    }
                    else
                    {
                        good=0;
                        break;
                    }
                }
                else
                {
                    if(b1>0)
                    {
                        b1--;
                        temp[idx]=0;
                    }
                    else if(b2>0)
                    {
                        b2--;
                        temp[idx]=1;
                    }
                    else
                    {
                        good=0;
                        break;
                    }
                }
                idx++;
            }

            if(good)
            {
                ans=temp;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
};