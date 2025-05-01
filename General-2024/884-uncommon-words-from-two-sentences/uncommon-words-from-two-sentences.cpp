class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> fr;
        int it=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                fr[s1.substr(it,i-it)]++;
                it = i+1;
            }
        }
        fr[s1.substr(it)]++;

        it=0;
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                fr[s2.substr(it,i-it)]++;
                it = i+1;
            }
        }
        fr[s2.substr(it)]++;

        vector<string> res;
        for(auto i:fr){
            if(i.second ==1){
                res.push_back(i.first);
            }
        }

        return res;
    }
};