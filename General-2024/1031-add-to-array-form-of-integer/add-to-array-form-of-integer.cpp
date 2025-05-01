class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        int rem=0 ,i=0;
        while(k || rem){
            if(i>= num.size()) num.push_back(0);
            
            int sum = rem + k%10 + num[i];
            k /=10;
            rem = sum/10;
            num[i]=sum%10;
            i++;
        }

        reverse(num.begin(),num.end());
        return num;
    }
};