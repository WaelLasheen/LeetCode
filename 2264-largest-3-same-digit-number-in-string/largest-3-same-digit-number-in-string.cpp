class Solution {
public:
    string largestGoodInteger(string num) {
        string res="";
        for(int i=0;i<num.size()-2;i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                res=max(res,num.substr(i,3));
                // skip two next digits
                i +=2;
            }
        }

        return res;
    }
};