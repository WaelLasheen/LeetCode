class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // sorry variable naming not the best thing
        int tcnt1=0 ,bcnt1=0 ,cnt1=0;   // count of top and bottom that equal to top[0]
        int tcnt2=0 ,bcnt2=0 ,cnt2=0;   // count of top and bottom that equal to bottom[0]
        int s=tops.size();
        for(int i=0;i<s;i++){
            if(tops[i]== tops[0] || bottoms[i] == tops[0]){
                cnt1++;
                if(tops[i]== tops[0]){
                    tcnt1++;
                }
                if(bottoms[i] == tops[0]){
                    bcnt1++;
                }
            }

            if(tops[i]== bottoms[0] || bottoms[i] == bottoms[0]){
                cnt2++;
                if(tops[i]== bottoms[0]){
                    tcnt2++;
                }
                if(bottoms[i] == bottoms[0]){
                    bcnt2++;
                }
            }
        }

        int res1= cnt1==s? -(s-max(tcnt1 ,bcnt1)) : 1;
        int res2= cnt2==s? -(s-max(tcnt2 ,bcnt2)) : 1;

        return -min(res1,res2);
    }
};