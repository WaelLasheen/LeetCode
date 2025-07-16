class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int se=0 ,so=0 ,o=0,e=0;
        for(int i:nums){
            // odd num
            if(i&1){
                if(se&1){
                    se++;
                }
                if(!(so&1)){
                    so++;
                }
                o++;
            }
            else{
                if(so&1){
                    so++;
                }
                if(!(se&1)){
                    se++;
                }
                e++;
            }
        }
        return max({se,so,o,e});
    }
};