class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // original [a1 ,a2 ,a3 ,a4]
        // derived [a1^a2 ,a2^a3 ,a3^a4 ,a4^a1]
        // in derived each number appear 2 times
        // so XOR of all derived must be zero to be valid
        int res=0;
        for(int i:derived){
            res ^=i;
        }

        return !res;
    }
};