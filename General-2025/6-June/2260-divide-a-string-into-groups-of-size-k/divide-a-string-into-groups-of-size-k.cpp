class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> arr;
        for(int i=0;i<s.size();i +=k){
            string sub="";
            for(int j=0;j<k;j++){
                if(i+j <s.size()){
                    sub +=s[i+j];
                } else{
                    sub += fill;
                }
            }
            arr.push_back(sub);
        }

        return arr;
    }
};