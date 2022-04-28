class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n=arr.size(), m=arr[0].size(), tne=n*m, cnt=0;
        int minr=0, minc=0, maxr=n-1, maxc=m-1;
        vector<int> ans;
        while(cnt<tne)
        {
            for(int i=minr, j=minc; j<=maxc and cnt<tne; j++)
            {
                ans.push_back(arr[i][j]);
                cnt++;
            }
            minr++;
            for(int i=minr, j=maxc; i<=maxr and cnt<tne; i++)
            {
                ans.push_back(arr[i][j]);
                cnt++;
            }
            maxc--;
            for(int i=maxr, j=maxc; j>=minc and cnt<tne; j--)
            {
                ans.push_back(arr[i][j]);
                cnt++;
            }
            maxr--;
            for(int i=maxr, j=minc; i>=minr and cnt<tne; i--)
            {
                ans.push_back(arr[i][j]);
                cnt++;
            }
            minc++;
        }
        return ans;
    }
};