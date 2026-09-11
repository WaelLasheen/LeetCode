class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> nums;
        for(int i=0;i<digits.size();i++){
            for(int j=0;j<digits.size();j++){
                for(int k=0;k<digits.size();k++){
                    if(i!=j && j!=k && i!=k && digits[i] && !(digits[k]&1)){
                        nums.insert(digits[i]*100+digits[j]*10+digits[k]);
                    }
                }
            }
        }

        return nums.size();
    }
};