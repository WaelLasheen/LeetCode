class Solution {
public:
    int res=0;
    set<string> subs;
    void backtrack(string s,int start){
        if(start == s.size()){
            return;
        }
        
        for(int i=start;i<s.size();i++){
            string sub=s.substr(start,i-start+1);
            if(!subs.count(sub)){
                subs.insert(sub);
                int subs_start = subs.size();
                res=max(res,subs_start);
                backtrack(s,i+1);
                subs.erase(sub);
            }
        }

    }

    int maxUniqueSplit(string s) {
        backtrack(s,0);

        return res;
    }
};