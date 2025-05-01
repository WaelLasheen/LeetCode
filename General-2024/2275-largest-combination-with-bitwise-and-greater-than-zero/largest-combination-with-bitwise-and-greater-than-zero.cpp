class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(32,0);
        int res=0;
        for(int i:candidates){
            int n=i ,it=0;
            while(n){
                bits[it] += n&1;
                n >>=1;
                res = max(res,bits[it]);
                it++;
            }

        }

        return res;
    }
};