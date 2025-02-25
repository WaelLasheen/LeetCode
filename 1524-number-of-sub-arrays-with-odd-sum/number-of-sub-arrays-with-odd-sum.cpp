class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // vector<vector<int>> dp(2,vector<int>(arr.size()+1,0));
        //   1 3 5
        // 0 1 1 0       even
        // 1 2 1 1       odd
        // if curr is even -> pass value as it in i+1 and for oven ++
        // if curr is odd -> pass value in reverse -even to odd and odd to even- i+1 and for odd ++

        int res=0 ,even=0,odd=0 ,mod =1e9+7;
        for(int i=arr.size()-1;i>-1;i--){
            if(arr[i] &1){
                swap(even,odd);
                odd = (odd+1)%mod;
            } else{
                even = (even+1)%mod;
            }
            
            res = (res + odd)%mod;
        }

        return res;
    }
};