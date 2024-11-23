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
                    res[it][r-i-1] = '#';
                    it--;
                }
                else{   // box ceil is *
                    it= j;
                    res[it][r-i-1] = '*';
                    it--;
                }
            }
        }
        
        return res;
    }
};