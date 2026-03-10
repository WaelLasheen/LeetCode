class Solution {
public:
    int minPartitions(string n) {
        int res=0;
        for(char d:n){
            res = max(res,d-'0');
        }

        return res;
    }
};
/*
    1
    10
    11
    100
    101
    110
    111
    .......
*/