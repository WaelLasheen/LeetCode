class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int r=box.size() ,c=box[0].size();
        vector<vector<char>> res(c,vector<char>(r,'.'));
        
        for(int i=r-1;i>=0;i--){
            int it=c-1;
            for(int j=c-1;j>=0;j--){
                if(box[i][j]=='.'){
                    continue;
                }
                else if(box[i][j]=='#'){
                    res[it][i] = '#';
                    it--;
                }
                else{   // box ceil is *
                    it= j;
                    res[it][i] = '*';
                    it--;
                }
            }
        }
        for(int i=0;i<c;i++){
            reverse(res[i].begin(),res[i].end());
        }

        return res;
    }
};