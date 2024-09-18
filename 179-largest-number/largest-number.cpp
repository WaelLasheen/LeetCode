class Solution {
public:

    static bool compare(const string& a, const string& b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>sn; // string num
        string out="";
        for(int i=0;i<nums.size();i++)
            sn.push_back(to_string(nums[i]));
        sort(sn.begin(),sn.end(),compare);
        if(sn[0]=="0")  // no need to loop as it will stay 0
            return"0";
        for(int i=0;i<nums.size();i++)
            out +=sn[i];
        return out;
    }
};