class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> poss;
        int l=0 ,r=0;
        while(r<word.size()){
            int fr=0;
            while(r<word.size() && word[l]==word[r]){
                fr++;
                r++;
            }
            if(fr>1){
                poss.push_back(fr-1);
            }
            l=r;
        }
        int res= accumulate(poss.begin(),poss.end(),0)+1;

        return res;
    }
};