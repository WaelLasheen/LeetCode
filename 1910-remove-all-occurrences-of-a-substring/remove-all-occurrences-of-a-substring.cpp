class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res="";  // use it as stack and answer at same time
        for(char i:s){
            res +=i;
            if(res.size() >= part.size()){
                int l=res.size()-1 ,r=part.size()-1;
                bool del=true;
                while(r >-1){
                    if(res[l--] != part[r--]){
                        del =false;
                        break;
                    }
                }
                int k=part.size();
                while(del && k--){
                    res.pop_back();
                }
            }
        }

        return res;
    }
};