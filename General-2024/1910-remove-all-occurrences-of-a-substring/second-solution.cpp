class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> box;
        reverse(part.begin(),part.end());
        for(char i:s){
            box.push(i);
            if(box.size() >=  part.size()){
                string sub="";
                int k=part.size();
                while(k--){
                    sub += box.top();
                    box.pop();
                }

                if(sub != part){
                    for(int j=part.size()-1;j>-1;j--){
                        box.push(sub[j]);
                    }
                }
            }
        }

        string res="";
        while(box.size()){
            res +=box.top();
            box.pop();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};