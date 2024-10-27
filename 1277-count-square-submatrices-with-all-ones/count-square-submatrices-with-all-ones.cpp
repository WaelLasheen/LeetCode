class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r=matrix.size() ,c=matrix[0].size() ,res=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i) matrix[i][j]+= matrix[i-1][j];
                if(j) matrix[i][j]+= matrix[i][j-1];
                if (i && j) matrix[i][j]-= matrix[i-1][j-1];
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]){
                    for(int it=0; ;it++){
                        if(i+it >=r || j+it >=c) break;
                        int val=matrix[i+it][j+it];
                        if(i) val -=matrix[i-1][j+it];
                        if(j) val -=matrix[i+it][j-1];
                        if (i && j) val += matrix[i-1][j-1];

                        int seq= it+1;
                        if(seq*seq == val) res++;
                    }
                }
            }
        }
        

        return res;
    }
};