class Solution {
public:
    bool check(vector<int>& nums) {
        int s= nums.size();
        bool res=true;
        for(int i=0;i<s;i++){
            for(int it=0;it<s-1;it++){
                if(nums[(it+i)%s] > nums[(it+i+1)%s]){
                    res=false;
                    break;
                } else{
                    res=true;
                }
            }

            if(res){
                return true;
            }
        }


        return res;
    }
};