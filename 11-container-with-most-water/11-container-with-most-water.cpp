class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0, e=height.size()-1, mXarea=INT_MIN;
        while(s<=e)
        {
            int H = min(height[s],height[e]);
            int area = (e-s)*H;
            mXarea = max(mXarea, area);
            if(height[s]>height[e]) e--;
            else s++;
        }
        return mXarea;
    }
};