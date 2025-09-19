class Spreadsheet {
public:
    unordered_map<string,int> mp;

    Spreadsheet(int rows) {}
    
    void setCell(string cell, int value) {
        mp[cell]=value;
    }
    
    void resetCell(string cell) {
        mp[cell]=0;
    }
    
    int getValue(string formula) {
        int i = findPlus(formula);
        string p1 = formula.substr(1,i-1);
        string p2 = formula.substr(i+1);
        
        return cal(p1) + cal(p2);
    }

    int findPlus(string formula){
        for(int i=0;i<formula.size();i++){
            if(formula[i]=='+'){
                return i;
            }
        }
        return -1;
    }

    int cal(string num){
        if(isdigit(num[0])){
            return stoi(num);
        }
        return mp[num];
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

 