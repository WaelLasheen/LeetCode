class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> res;
        int n=digits.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(!(digits[k]&1) && digits[i]){
                        res.insert(digits[i]*100+digits[j]*10+digits[k]);
                    }
                    if(!(digits[j]&1) && digits[i]){
                        res.insert(digits[i]*100+digits[k]*10+digits[j]);
                    }
                    if(!(digits[k]&1) && digits[j]){
                        res.insert(digits[j]*100+digits[i]*10+digits[k]);
                    }
                    if(!(digits[i]&1) && digits[j]){
                        res.insert(digits[j]*100+digits[k]*10+digits[i]);
                    }
                    if(!(digits[j]&1) && digits[k]){
                        res.insert(digits[k]*100+digits[i]*10+digits[j]);
                    }
                    if(!(digits[i]&1) && digits[k]){
                        res.insert(digits[k]*100+digits[j]*10+digits[i]);
                    }
                }
            }
        }

        vector<int> arr(res.begin(),res.end());
        return arr;
    }
};