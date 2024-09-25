class Solution {
public:
    int maxDepth(string s) {
        int res=0 ,c=0;
        for(const char i:s){
            if(i=='('){
                c++;
                res=max(res,c);
            }
            else if(i==')') c--;
        }

        return res;
    }
};