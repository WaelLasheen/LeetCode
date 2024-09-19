class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r=img.size() ,c=img[0].size();
        vector<vector<int>> res(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int num=1 ,sum=img[i][j];
                if(i >0){
                    num++;
                    sum+=img[i-1][j];
                    if(j >0){
                        num++;
                        sum+=img[i-1][j-1];
                    }
                    if(j+1 <c){
                        num++;
                        sum+=img[i-1][j+1];
                    }
                }
                if(i+1 <r){
                    num++;
                    sum+=img[i+1][j];
                    if(j >0){
                        num++;
                        sum+=img[i+1][j-1];
                    }
                    if(j+1 <c){
                        num++;
                        sum+=img[i+1][j+1];
                    }
                }
                if(j >0){
                    num++;
                    sum+=img[i][j-1];
                }
                if(j+1 <c){
                    num++;
                    sum+=img[i][j+1];
                }

                res[i][j]= sum/num;
            }
        }

        return res;
    }
};