class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long mn=lower ,mx=upper;
        long sum=0;
        for(int i:differences){
            sum +=i;

            mn=max((long)mn ,lower-sum);
            mx=min((long)mx ,upper-sum);
        }

        return mx-mn+1>0? mx-mn+1 : 0;
    }
};


/*
    x2-x1=1
    x3-x2=-3
    x4-x3=4

    x2=1+x1     1 5
    x3=-2+x1    3 5
    x4=2+x1     3 4
    
    4-3+1 = 2
*/