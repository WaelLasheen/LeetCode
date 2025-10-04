class Solution {
public:
    int maxArea(vector<int>& height) {
        int mArea=0;
        int r=height.size()-1,l=0;
        while(l<r){
            int area=(r-l)*min(height[l],height[r]);
            mArea=max(mArea,area);
            height[l]>height[r]? r--:l++;
        }
        return mArea;
    }
};