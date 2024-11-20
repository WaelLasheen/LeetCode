class Solution {
public:
    int takeCharacters(string s, int k) {
        if(!k) return 0;  // edge case

        vector<int> abc(3,0);
        int len = s.size(), res=len;
        bool f=true;    // to get first valid one from left
        for(int i=0;i<len;i++){
            abc[s[i]-'a']++;
            if(f && abc[0]>=k && abc[1]>=k && abc[2]>=k){
                res=i+1;
                f=false;
            }
        }

        if(abc[0] <k || abc[1] <k || abc[2] <k){
            return -1;
        }

        // if I take all string it it valid, but I need to reduce it as possible
        int l= len-1, r=l;
        vector<int> fr(3,0);   // freq of chars that token from right
        while(r>=0){
            fr[s[r]-'a']++;

            while(l>=0 && abc[s[l]-'a']-1 + fr[s[l]-'a'] >=k){
                abc[s[l]-'a']--;
                l--;
            }
            
            res = min(res ,l+1+len-r);
            r--;
        }
        
        return res;
    }
};