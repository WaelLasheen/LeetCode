class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int> fr;
        for(const char i:allowed){
            fr[i]++;
        }
        int res=0;

        for(const string i:words){
            for(int j=0;j<i.size();j++){
                if(!fr[i[j]]){
                    break;
                }
                if(j==i.size()-1){
                    res++;
                }
            }
        }
        
        return res;
    }
};