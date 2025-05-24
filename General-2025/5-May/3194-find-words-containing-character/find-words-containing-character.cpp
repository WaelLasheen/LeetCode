class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ind;
        for(int i=0;i<words.size();i++){
            for(char j:words[i]){
                if(j==x){
                    ind.push_back(i);
                    break;
                }
            }
        }

        return ind;
    }
};