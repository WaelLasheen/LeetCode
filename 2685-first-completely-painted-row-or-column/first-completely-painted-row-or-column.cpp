class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row=mat.size() ,col=mat[0].size();
        vector<vector<int>> its(row*col+1,vector<int>(2));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int ind= mat[i][j];
                its[ind][0]=i;
                its[ind][1]=j;
            }
        }

        vector<int> rowsFr(row,0) ,colsFr(col,0);
        for(int i=0;i<arr.size();i++){
            rowsFr[its[arr[i]][0]]++;
            colsFr[its[arr[i]][1]]++;
            if(rowsFr[its[arr[i]][0]] == col || colsFr[its[arr[i]][1]]== row){
                return i;
            }
        }

        return -1;
    }
};