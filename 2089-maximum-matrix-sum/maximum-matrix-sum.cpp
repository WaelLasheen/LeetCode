#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll absSum=0;
        int neg=0 ,absMin=INT_MAX;
        for(vector<int> i:matrix){
            for(int j:i){
                absSum +=abs(j)*1LL;    //1LL to convert j to long long to handel overflow
                absMin=min(absMin,abs(j));
                if(j<0){
                    neg++;
                }
            }
        }

        return neg&1? absSum -2*absMin : absSum;
    }
};