class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c=0;
        // map<string,bool> v;
        for(string i:logs){
            if(i== "./"){
                continue;
            }else if(i== "../"){
                if(c > 0) c--;
            }else{
                c++;
            }
        }
        return c;
    }
};