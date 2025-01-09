class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> it;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                it.push_back(i);
            }
        }
        vector<int> res(boxes.size(),0);
        for(int i=0;i<boxes.size();i++){
            for(int j:it){
                res[i] += abs(i-j);
            }
        }

        return res;
    }
};