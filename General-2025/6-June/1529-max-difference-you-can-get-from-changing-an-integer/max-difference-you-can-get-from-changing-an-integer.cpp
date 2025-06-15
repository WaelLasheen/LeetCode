class Solution {
public:
    int maxDiff(int num) {
        string mn=to_string(num);
        string mx=to_string(num);

        int it1=0 ,it2=0;
        while(it1+1<mx.size() && mx[it1]=='9'){
            it1++;
        }
        while(it2+1<mn.size() && mn[it2]<='1'){
            it2++;
        }

        char mnd=mn[it2] ,mxd=mx[it1] ,c= mnd!=mn[0]?'0':'1';

        for(int i=0;i<mn.size();i++){
            if(mn[i]==mnd){
                mn[i]= c;
            }
            if(mx[i]==mxd){
                mx[i]='9';
            }
        }

        return stoi(mx)-stoi(mn);
    }
};