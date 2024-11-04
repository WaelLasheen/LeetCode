class Solution {
public:
    string compressedString(string word) {
        int l=0,r=0 ,n=word.size();
        string res="";
        while(r<n){
            int c=0;
            while(r<n && word[r]==word[l] && c<9){
                c++;
                r++;
            }
            res += char(c+'0');
            res += word[l];
            l=r;
        }

        return res;
    }
};