class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int rem=baskets.size();
        for(int i:fruits){
            for(int j=0;j<baskets.size();j++){
                if(i <= baskets[j]){
                    rem--;
                    baskets[j]=0;
                    break;
                }
            }
        }

        return rem;
    }
};