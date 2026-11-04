class Solution {
public:

    // x even and y odd 
    // what option i have ? 
    // x+1 even , y-1 odd
    // x-1 even , y+1 odd
    // odd-> 0 : i win
    // 

    bool xorGame(vector<int>& arr) {
        {
            unordered_map<int,int>cnt;
            for(int& x : arr)
                cnt[x]++;
            vector<int>temp;
            for(auto& [val,freq] : cnt)
                if(freq&1)
                    temp.push_back(val);
            arr=temp;
        }
        int allXor=0;
        for(int& x : arr)
            allXor^=x;
        if(!allXor)
            return 1;
        
        int n=arr.size();
        if(n&1)
            return 0;
        return 1;
    }
};