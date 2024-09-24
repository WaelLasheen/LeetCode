class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> prefix;
        for(int& i:arr1){
            while(i && !prefix.count(i)){
                prefix.insert(i);
                i /=10;
            }
        }

        int res=0;
        for(int& i:arr2){
            while(i && !prefix.count(i)){
                i /=10;
            }

            if(i){
                int len = to_string(i).size();
                res=max(res ,len);
            }
        }

        return res;
    }
};