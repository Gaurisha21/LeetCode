class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1, mx=0;
        while(i<j)
        {
            int w=j-i;
            mx = height[i]<height[j] ? max(mx, height[i++]*w) : max(mx, height[j--]*w);
        }
        return mx;
    }
};