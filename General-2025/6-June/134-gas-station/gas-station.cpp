class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> net(n);
        for(int i=0;i<n;i++){
            net[i] = gas[i]-cost[i];
            // prefix
            if(i){
                net[i] +=net[i-1];
            }
        }

        if(net.back()<0){
            return -1;
        }

        int bias=0 ,it=0;
        for(int i=0;i<n;i++){
            if(net[i]+bias <0){
                bias = -net[i];
                it=i+1;
            }
        }
        

        return it;
    }
};