class Solution {
public:
    string getHappyString(int n, int k) {
        string res = "";
        if(k > (3<<(n-1))){
            return res;
        }
        // we use zero index and he use one index so we sub 1 from k to be zero index
        k--;    
        int numOfElemnt = 1<<(n-1);
        int c= k/numOfElemnt;
        res += (c + 'a');
        int l= numOfElemnt * c ,r= numOfElemnt * (c+1)-1;
        while(l<=r && res.size()<n){
            int mid = (l+r)/2;
            if(k <= mid){
                r = mid-1;
                res += getChar(res.back(),true);
            }
            else if(k > mid){
                l = mid+1;
                res += getChar(res.back(),false);
            }
        }
        return res;
    }

    char getChar(char c ,bool isMin){
        if(c=='a') return isMin? 'b':'c';
        if(c=='b') return isMin? 'a':'c';
        // 'c' case
        return isMin? 'a':'b';
    }
};