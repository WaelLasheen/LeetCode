class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=1 ,s=digits.size();
        for(int i=s-1;i>-1;i--){
            if(digits[i]+c <10){
                digits[i]++;
                c=0;
                break;
            }
            else{
                digits[i]=0;
            }
        }
        if(c==1){
            digits.resize(s+1,0);
            digits[0]=1;
        }
        
        return digits;
    }
};