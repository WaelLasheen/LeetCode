class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string nums="123456789";
        vector<int>out;
        for(int i=0;i<9;i++){
            for(int j=2;j<=9-i;j++){
                long n=stol(nums.substr(i,j));
                if(n>=low && n<=high)
                    out.push_back(n);
            }
        }
        sort(out.begin(),out.end());
        return out;
    }
};