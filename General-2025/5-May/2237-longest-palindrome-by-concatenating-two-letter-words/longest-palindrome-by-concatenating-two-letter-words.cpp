class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(string i:words){
            mp[i]++;
        }

        int res=0;
        bool mid=false;
        for(auto [key,val]: mp){
            if(key[0] != key[1]){
                string rKey= string(1,key[1])+key[0];
                if(mp.count(rKey)){
                    res += min(val ,mp[rKey])*2;
                }
            } else if(val&1){
                res += 2*(val-1);
                mid=true;
            } else{
                res +=2*val;
            }
        }

        return res + mid*2;
    }
};