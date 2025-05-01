class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for(char i:s) mp[i]++;

        int res=0 ;
        bool f=false;
        for(auto i:mp){
            if((i.second) &1){
                res +=i.second-1;
                f=true;
            } else{
                res += i.second;
            }
        }

        return res+f;
    }
};