class Solution {
public:

    // 1 1 1
    // 0 0 1
    // 0 0 0
    // 1 1 0

    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size()+1;
        if(nums.size()==2){
            return 2;
        }
        if((n&(n-1))==0){
            if(n==2){
                return n-1;
            }
            else{
                return n;
            }
        }
        else{
            while((n&(n-1))!=0){
                n++;
            }
            return n;
        }
    }
};