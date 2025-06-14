class Solution {
public:
    int minMaxDifference(int num) {
        string mn=to_string(num);
        for(int i=1;i<mn.size();i++){
            if(mn[i]==mn[0]){
                mn[i]='0';
            }
        }
        mn[0]='0';

        string mx=to_string(num);
        int it=0;
        while(it+1<mx.size() && mx[it]=='9'){
            it++;
        }
        for(int i=it+1;i<mx.size();i++){
            if(mx[i]==mx[it]){
                mx[i]='9';
            }
        }
        mx[it]='9';

        return stoi(mx)-stoi(mn);
    }
};