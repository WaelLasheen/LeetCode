#define ll long long

class Solution {
public:
    long long minimumSteps(string s) {
        ll res=0;
        int it=0 ,len=s.size();
        while(it<len && !(s[it]-'0')){
            it++;
        }
        for(int i=it;i<len;i++){
            if(!(s[i]-'0')){
                res += 1ll*(i-it);
                it++;
            }
        }

        return res;
    }
};