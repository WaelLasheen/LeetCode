class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n,vector<int>(n));
        int top=0 ,bottom=n-1 ,left=0 ,right=n-1;

        int num=1;
        n *=n;
        while(num <= n){
            // left to right
            for(int i=left;i<= right;i++){
                res[top][i] = num;
                num++;
                if(num > n){
                    return res;
                }
            }
            top++;

            // top to bottom
            for(int i=top;i<= bottom;i++){
                res[i][right] = num;
                num++;
                if(num > n){
                    return res;
                }
            }
            right--;

            // right to left
            for(int i=right;i>= left;i--){
                res[bottom][i] = num;
                num++;
                if(num > n){
                    return res;
                }
            }
            bottom--;

            // bottom to top
            for(int i=bottom;i>= top;i--){
                res[i][left] = num;
                num++;
                if(num > n){
                    return res;
                }
            }
            left++;
        }

        return res;
    }
};