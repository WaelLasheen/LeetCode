class Solution {
public:
    int candy(vector<int>& ratings) {
        int s= ratings.size();
        vector<int> candies(s,1);
        // check left neightbor
        for(int i=1;i<s;i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }

        // check right neightbor
        for(int i=s-2;i>=0;i--){
            if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]){
                candies[i] = candies[i+1]+1;
            }
        }

        return accumulate(candies.begin(),candies.end(),0);
    }
};