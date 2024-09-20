class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int p1=100 ,p2=100;
        for(int p:prices){
            if(p< p2){
                if(p<p1){
                    p2=p1;
                    p1=p;
                } else{
                    p2=p;
                }
            }
        }

        return p1+p2 <= money? money-(p1+p2) : money;
    }
};