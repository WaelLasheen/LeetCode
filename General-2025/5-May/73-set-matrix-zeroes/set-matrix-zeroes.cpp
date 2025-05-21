class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<bool> rz(r,false) ,cz(c,false);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    rz[i] =true;
                    cz[j] =true;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(rz[i] || cz[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};