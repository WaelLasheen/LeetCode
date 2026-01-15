class Solution {
public:
    // int maxSide(vector<int>& arr){}

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        int curr=1 ,next=2 ,mxa=1;
        for(int i:hBars){
            if(i==next){
                next++;
            } else{
                mxa= max(mxa , next-curr);
                curr= i-1;
                next= i+1;
            }
        }
        mxa= max(mxa , next-curr);

        sort(vBars.begin(),vBars.end());
        curr=1 ,next=2 ;
        int mxb=1;
        for(int i:vBars){
            if(i==next){
                next++;
            } else{
                mxb= max(mxb , next-curr);
                curr= i-1;
                next= i+1;
            }
        }
        mxb= max(mxb , next-curr);

        int mn = min(mxa ,mxb);
        return mn*mn;
    }
};