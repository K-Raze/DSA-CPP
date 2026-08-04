class Solution {
public:
    vector<int> findMissingElements(vector<int>& arr) {
        int start=*min_element(arr.begin(),arr.end());
        int end=*max_element(arr.begin(),arr.end());
        vector<int>count(105,0);
        for(int num : arr)
            count[num]++;
        vector<int>ans;
        for(int i=start;i<=end;i++)
            if(!count[i])
                ans.push_back(i);
        return ans;
    }
};