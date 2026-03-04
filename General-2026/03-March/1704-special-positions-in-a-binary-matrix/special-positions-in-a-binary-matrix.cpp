class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size() ,m=mat[0].size() ,res=0;
        vector<int> rSum(n,0) ,cSum(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rSum[i] +=mat[i][j];
                cSum[j] +=mat[i][j];
            }
        }

        for(int i=0;i<n;i++){
            if(rSum[i]==1){
                for(int j=0;j<m;j++){
                    if(mat[i][j] && cSum[j] ==1){
                        res++;
                        break;
                    }
                }
            }
        }

        return res;
    }
};