// nice solution 
// https://youtu.be/wPLneNcCOyI?si=P6BYjMXZsf2HSZMn
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int s= colors.size();
        for(int i=0;i<s;i++){
            colors.push_back(colors[i]);
        }
        vector<int> good(2*s ,1);
        for(int i=1;i<2*s;i++){
            if(abs(colors[i]-colors[i-1])){
                good[i] +=good[i-1];
            }
        }
        int res=0;
        for(int i=0;i<s;i++){
            if(good[i+k-1] - good[i] == k-1) res++;
        }

        return res;
        // 0 1 0 1 0 0 1 0 1 0
        // 1 2 3 4 5 1 2 3 4 5
    }
};