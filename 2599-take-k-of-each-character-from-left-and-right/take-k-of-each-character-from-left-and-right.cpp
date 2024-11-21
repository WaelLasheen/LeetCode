class Solution {
public:
    int takeCharacters(string s, int k) {
        if(!k) return 0;

        int len=s.size();
        s +=s;
        int res=-1;
        vector<int> abc(3,0);
        for(int i=0;i<len;i++){
            abc[s[i]-'a']++;
            if(abc[0] >=k && abc[1] >=k && abc[2] >=k){
                res= i+1;
                break;
            }
        }

        if(res==-1){
            return res;
        }

        int l=0 ,r=0;
        abc={0,0,0};
        while(r<2*len){
            abc[s[r]-'a']++;
            while(abc[s[l]-'a']>k){
                abc[s[l]-'a']--;
                l++;
            }

            if(r>=len-1 && l<= len-1){
                res=min(res,r-l+1);
            }

            r++;
        }

        return res;
    }
};