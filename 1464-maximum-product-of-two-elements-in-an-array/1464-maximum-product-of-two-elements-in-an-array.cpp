class Solution
{
    public:
        int maxProduct(vector<int> &arr)
        {
            priority_queue<int, vector < int>, greater < int>> pq;
            pq.push(arr[0]);
            pq.push(arr[1]);
            for (int i = 2; i < arr.size(); i++)
            {
                if (arr[i] > pq.top())
                {
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
            int ans = 1;
            while (!pq.empty())
            {
                ans *= pq.top()-1;
                pq.pop();
            }
            return ans;
        }
};