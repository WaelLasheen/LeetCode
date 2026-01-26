class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int diff = INT_MAX;
        sort(arr.begin(),arr.end());

        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1] - arr[i] < diff){
                diff = arr[i+1] - arr[i];
                res = {{arr[i], arr[i+1]}};
            }
            else if(arr[i+1] - arr[i] == diff){
                res.push_back({arr[i], arr[i+1]});
            }
        }

        return res;
    }
};