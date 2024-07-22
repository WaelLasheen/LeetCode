class Solution {
public:
    int kthGrammar(int n, int k) {
        int curr=0;
        int l=1 ,r= 1<<(n-1);
        n--;
        while(n--){
            int mid = (l+r)/2;
            if(mid >= k){
                // you are in left and update right
                r = mid;
            }else{
                // you are in right and update left
                l = mid+1;
                curr = (curr? 0 : 1);
            }
        }

        return curr;
    }
};
/*
0
01
0110
0110101
0110100110010110
01101001100101101001011001101001

left part is same of previous and right part is invert of previous
*/