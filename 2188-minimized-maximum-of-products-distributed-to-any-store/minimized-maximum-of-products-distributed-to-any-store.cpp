class Solution {
public:
    int helper(vector<int>& q ,int div){
        int res = 0;
        for(int i:q){
            res += (i+div-1)/div;   // same ceil function
        }
        return res;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1 ,r= *max_element(quantities.begin(),quantities.end()); 
        int res=r;

        while(l<=r){
            int mid = (l+r)/2;
            if(helper(quantities,mid) <= n){
                r= mid-1;
                res = mid;
            }
            else{
                l= mid+1;
            }
        }

        return res;
    }
};