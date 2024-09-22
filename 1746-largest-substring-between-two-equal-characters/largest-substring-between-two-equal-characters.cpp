class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,vector<int>> it;
        for(int i=0;i<s.size();i++){
            if(it[s[i]].size() !=2){
                it[s[i]].push_back(i);
            } else{
                it[s[i]][1]=i;
            }
        }

        int dis=-1;
        for(auto i:it){
            if(i.second.size()==2){
                dis=max(dis,i.second[1]-i.second[0]-1);
            }
        }

        return dis;
    }
};