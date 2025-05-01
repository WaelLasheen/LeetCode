class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int s=customers.size();
        long t=0 ,curr=customers[0][0];
        for(int i=0;i<s-1;i++){
            curr +=customers[i][1];
            t += customers[i][1];
            if(customers[i+1][0] < curr){
                t += (curr-customers[i+1][0]);
            }else{
                curr = customers[i+1][0];
            }
        }
        return (t+customers[s-1][1])/(s*1.0);
    }
};