class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int dis=-1;
        map<char,int> it;
        for(int i=0;i<s.size();i++){
            if(it.find(s[i]) != it.end()){
                dis=max(dis, i-it[s[i]]-1);
            } else{
                it[s[i]]=i;
            }
        }

        return dis;
    }
};