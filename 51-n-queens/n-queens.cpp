class Solution {
public:
    vector<vector<string>> res;
    vector<bool> md,umd,col;

    void queen(int n ,vector<string>& arr ,int q,int i){

        if(q==n){
            res.push_back(arr);
            return;
        }

        for( ;i<n;i++){
            for(int j=0;j<n;j++){
                // main diameter i-j = const
                // unmain diameter i+j = const

                if(!md[n-1+i-j] && !umd[i+j] && !col[j]){
                    md[n-1+i-j]=true;
                    umd[i+j]=true;
                    col[j]=true;
                    arr[i][j]='Q';
                    queen(n,arr,q+1,i+1);
                    md[n-1+i-j]=false;
                    umd[i+j]=false;
                    col[j]=false;
                    arr[i][j]='.';
                }
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        col.resize(n,false);
        md.resize(2*n-1,false);
        umd.resize(2*n-1,false);

        string s=string(n,'.');
        vector<string> arr(n,s);
        queen(n,arr,0,0);

        return res;
    }
};