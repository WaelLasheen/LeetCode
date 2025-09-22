class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mfr=0 ,res=0;
        map<int,int>fr;
        for(int n:nums){
            fr[n]++;
            if(fr[n] == mfr){
                res += mfr;
            }
            if(fr[n] > mfr){
                mfr = fr[n];
                res = mfr;
            }
        }
        
        return res;
    }
};