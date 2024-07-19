class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size() ,n=matrix[0].size();
        vector<int> res;
        for(int i=0;i<m;i++){
            int minr=matrix[i][0] ,mri=0;
            // first find min in row
            for(int j=0;j<n;j++){
                if(minr >matrix[i][j]){
                    minr = matrix[i][j];
                    mri=j;
                }
            }
            int maxc = minr;
            // then check if it max in colum
            for(int j=0;j<m;j++){
                if(maxc <matrix[j][mri]){
                    maxc = matrix[j][mri];
                }
            }
            if(minr == maxc) res.push_back(maxc);
        }

        return res;
    }
};
