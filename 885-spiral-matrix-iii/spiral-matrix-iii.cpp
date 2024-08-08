class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> spiral;
        spiral.push_back({rStart,cStart});
        int r=1,d=1,l=2,u=2;
        int i=rStart ,j=cStart;

        while(spiral.size() != rows*cols){
            // move to right
            for(int x=0;x<r;x++){
                if(i>-1 && i< rows && j+1 >-1 && j+1< cols){
                    spiral.push_back({i,++j});
                }else{
                    j++;
                }
            }
            r +=2;
            if(spiral.size() == rows*cols) break;
            
            // move to down
            for(int x=0;x<d;x++){
                if(i+1>-1 && i+1< rows && j >-1 && j< cols){
                    spiral.push_back({++i,j});
                }else{
                    i++;
                }
            }
            d +=2;
            if(spiral.size() == rows*cols) break;

            // move to left
            for(int x=0;x<l;x++){
                if(i>-1 && i< rows && j-1 >-1 && j-1< cols){
                    spiral.push_back({i,--j});
                }else{
                    j--;
                }
            }
            l +=2;
            if(spiral.size() == rows*cols) break;

            // move to up
            for(int x=0;x<u;x++){
                if(i-1>-1 && i-1< rows && j >-1 && j< cols){
                    spiral.push_back({--i,j});
                }else{
                    i--;
                }
            }
            u +=2;
        }

        return spiral;
    }
};