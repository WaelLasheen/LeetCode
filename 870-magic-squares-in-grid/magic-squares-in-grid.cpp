class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res=0;
        int row = grid.size() ,col=grid[0].size();
        if(row <3 || col <3) return res;

        for(int i=0;i<row-2;i++){
            for(int j=0;j<col-2;j++){
                map<int,int> sumr,sumc;
                map<int,int> fr;
                int d1=0 ,d2=0;
                for(int a=0;a<3;a++){
                    for(int b=0;b<3;b++){
                        sumr[a] +=grid[i+a][b+j];
                        sumc[b] +=grid[i+a][b+j];

                        if(a==b)   d1 +=grid[i+a][b+j];
                        if(a+b==2) d2 +=grid[i+a][b+j];

                        fr[grid[i+a][b+j]]++;
                    }
                }
                bool x = max({d1,d2,sumr[0],sumr[1],sumr[2]}) == min({d1,d2,sumr[0],sumr[1],sumr[2]});
                if (sumr == sumc && x && fr.size() == 9) {
                    for(int n=1;n<10;n++){
                        if(!fr[n]){
                            res--;
                            break;
                        }
                    }
                    res++;
                }
            }
        }

        return res;
    }
};