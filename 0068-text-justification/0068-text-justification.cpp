class Solution {
public:
    vector<string> fullJustify(vector<string>& arr, int limit) {
        vector<string> ans;

        vector<string>temp;
        int tempLen=0;
        for(int i=0;i<arr.size();i++)
        {
            if(tempLen+arr[i].size()+temp.size()>limit)
            {   
                // build and insert
                int rem=limit-tempLen;
                if(temp.size()==1)
                {
                    string s=temp.front();
                    while(rem--)
                        s+=' ';
                    ans.push_back(s);
                }
                else
                {
                    int spaceAdd=rem/(temp.size()-1);
                    string spaceStr(spaceAdd,' ');
                    int spaceEx=rem%(temp.size()-1);
                    string s;
                    for(int i=0;i<temp.size();i++)
                    {
                        string word=temp[i];
                        s+=word;
                        if(i!=temp.size()-1)
                        {
                            s+=spaceStr;
                            if(spaceEx)
                            {
                                s+=' ';
                                spaceEx--;
                            }
                        }
                    }
                    ans.push_back(s);
                }
                // updates
                tempLen=arr[i].size();
                temp.clear();
                temp.push_back(arr[i]);
            }
            else
            {
                tempLen+=arr[i].size();
                temp.push_back(arr[i]);
            }
        }
        // build and insert
        
        string s;
        for(int i=0;i<temp.size();i++)
        {
            s+=temp[i];
            if(i!=temp.size()-1)
                s+=' ';
        }
        while(s.size()<limit)
            s+=' ';
        ans.push_back(s);
        return ans;
    }
};