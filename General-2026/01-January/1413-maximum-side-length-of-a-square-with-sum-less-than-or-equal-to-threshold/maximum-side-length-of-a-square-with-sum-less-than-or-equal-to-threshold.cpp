class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size() ,n=mat[0].size() ,res=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i) mat[i][j] += mat[i-1][j];
                if(j) mat[i][j] += mat[i][j-1];
                if(i && j) mat[i][j] -= mat[i-1][j-1];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int l=0 ,r=min(m-i ,n-j)-1;
                while(l<=r){
                    int k= (l+r)/2;

                    int sum = mat[i+k][j+k];
                    if(i) sum -= mat[i-1][j+k];
                    if(j) sum -= mat[i+k][j-1];
                    if(i && j) sum += mat[i-1][j-1];

                    if(sum <= threshold){
                        res = max(res,k+1);
                        l= k+1;
                    } else{
                        r= k-1;
                    }
                }                
            }
        }

        return res;
    }
};