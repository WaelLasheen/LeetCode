class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string i:words){
            string w=i;
            reverse(w.begin(),w.end());
            if(w==i){
                return i;
            }
        }
        return "";
    }
};