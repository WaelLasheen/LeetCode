class Solution {
public:
    int countOdds(int low, int high) {
        int len = high-low +1;
        // if len is even this mean half is odd and half is even
        if(!(len&1)){
            return len/2;
        }
        // if len is odd this mean there is different by 1 between even and odd
        // and this depend on the start
        if(low&1){
            return len/2+1;
        }

        return len/2;
    }
};