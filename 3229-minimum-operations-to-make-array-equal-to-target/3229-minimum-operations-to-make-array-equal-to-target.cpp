using ll=long long;
class Solution {
public:

    // 3 5 1 2 
    // 4 6 2 4
    // 1 1 1 2

    // 1 3 2 
    // 2 1 4
    // 1 -2 2 
    // x x -y x x

    long long minimumOperations(vector<int>& arr, vector<int>& target) {
        int n=arr.size();
        for(int i=0;i<n;i++)
            arr[i]=target[i]-arr[i];
        
        ll ans=abs(arr.front());
        ll temp=abs(arr.front());
        //  cout<<ans<<" "<<temp<<" ";
        for(int i=1;i<n;i++)
        {
            bool sameSign =
                (arr[i] > 0 && arr[i-1] > 0) ||
                (arr[i] < 0 && arr[i-1] < 0);
            if(!sameSign)
            {
                temp=abs(arr[i]);
                ans+=temp;
            }
            else if(abs(arr[i])>=abs(temp))
            {
                ans+=abs(arr[i])-abs(temp);
                temp=abs(arr[i]);
            }
            else
                temp=abs(arr[i]);
            // cout<<ans<<" "<<temp<<" ";
        }
        return ans;
    }
};