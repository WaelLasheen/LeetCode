class Solution {
public:
    int possibleStringCount(string word) {
        int l=0 ,r=0 ,res=1;
        while(r<word.size()){
            while(r<word.size() && word[l]==word[r]){
                r++;
            }
            if(r-l>1){
                res += r-l-1;
            }
            l=r;
        }

        return res;
    }
};