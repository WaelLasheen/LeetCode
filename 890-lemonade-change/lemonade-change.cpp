class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> coin(3,0);
        for(int i:bills){
            if(i==5){
                coin[0]++;
            }
            else if(i==10){
                if(coin[0]){
                    coin[0]--;
                    coin[1]++;
                }else{
                    return false;
                }
            }
            else{
                if(coin[0]&& coin[1] || coin[0]>2){
                    coin[2]++;  // no need to it ,but I love to add it.
                    if(coin[1]){
                        coin[0]--;
                        coin[1]--;
                    }else{
                        coin[0] -=3;
                    }
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};