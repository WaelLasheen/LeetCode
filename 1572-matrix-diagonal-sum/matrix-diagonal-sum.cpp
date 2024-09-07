class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int s=mat.size();
        int res=0;
        for(int i=0;i<s;i++){
            // primary diagonal
            res +=mat[i][i];
            // secondary  diagonal 
            res +=mat[i][s-i-1];
        }

        if(s&1) res -=mat[s/2][s/2];
        return res;
    }
};