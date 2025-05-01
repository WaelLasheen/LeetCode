class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        map<char,int>fr;
        int l=0 ,r=0 ,c=0;
        while(r !=s.size()){
            if(!(fr[s[r]])){
                fr[s[r]]++;
                r++;
                c++;
            }else{
                fr[s[l]]--;
                l++;
                c--;
            }
            res=max(res,c);
        }

        return res;
    }
};