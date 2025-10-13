class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res = {words[0]};
        map<char,int> pre;
        for(char i:words[0]) pre[i]++;

        for(int i=1;i<words.size();i++){
            map<char,int> curr;
            for(char j:words[i]) curr[j]++;
            
            if(pre != curr){
                pre = curr;
                res.push_back(words[i]);
            }
        }

        return res;
    }
};