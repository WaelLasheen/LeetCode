class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int trCnt=0 ,lessTrCnt=0;
        for(int i:nums){
            if(i < target){
                lessTrCnt++;
            }
            else if(i == target){
                trCnt++;
            }
        }
        vector<int> res(trCnt);
        for(int i=0;i<trCnt;i++){
            res[i] = lessTrCnt + i;
        }

        return res;
    }
};