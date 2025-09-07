class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n&1){
            res.push_back(0);
            n--;
        }

        while(n){
            res.push_back(n);
            res.push_back(-n);
            n -=2;
        }

        return res;
    }
};