class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int> fr;
        for(string i:words){
            for(char j:i){
                fr[j]++;
            }
        }

        for(auto i:fr){
            if(i.second% words.size()){
                return false;
            }
        }

        return true;
    }
};