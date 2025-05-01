class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> zo={0,0};  // zero & one freq
        for(int i:students){
            zo[i]++;
        }
        int s = sandwiches.size();
        for(int i=0;i<s;i++){
            if(!zo[sandwiches[i]]){
                return s-i;
            }
            zo[sandwiches[i]]--;
        }

        return 0;
    }
};