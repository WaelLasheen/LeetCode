class Solution {
public:
    int minMaxDifference(int num) {
        string mn=to_string(num);
        string mx=to_string(num);

        int it=0;
        while(it+1<mx.size() && mx[it]=='9'){
            it++;
        }

        char mnd=mn[0] ,mxd=mx[it];

        for(int i=0;i<mn.size();i++){
            if(mn[i]==mnd){
                mn[i]='0';
            }
            if(mx[i]==mxd){
                mx[i]='9';
            }
        }

        return stoi(mx)-stoi(mn);
    }
};