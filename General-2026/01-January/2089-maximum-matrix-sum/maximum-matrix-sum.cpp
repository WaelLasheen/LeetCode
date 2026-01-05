#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size() ,mn= abs(matrix[0][0]);
        bool isOdd=false;   // number of negative value is odd
        ll sum=0; 

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val = matrix[i][j];
                sum += abs(val)* 1LL;
                mn= min(mn ,abs(val));
                if(val <0){
                    isOdd = !isOdd;
                }
            }
        }

        return sum - 2*mn*isOdd;
    }
};