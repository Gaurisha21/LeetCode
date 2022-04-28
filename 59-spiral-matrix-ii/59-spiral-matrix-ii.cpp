class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m=n, tne=n*m, cnt=1;
        int minr=0, minc=0, maxr=n-1, maxc=m-1;
        vector<vector<int>> ans(n,vector<int>(n,0));
        while(cnt<=tne)
        {
            for(int i=minr, j=minc; j<=maxc and cnt<=tne; j++)
            {
                ans[i][j]=cnt;
                cnt++;
            }
            minr++;
            for(int i=minr, j=maxc; i<=maxr and cnt<=tne; i++)
            {
                ans[i][j]=cnt;
                cnt++;
            }
            maxc--;
            for(int i=maxr, j=maxc; j>=minc and cnt<=tne; j--)
            {
                ans[i][j]=cnt;
                cnt++;
            }
            maxr--;
            for(int i=maxr, j=minc; i>=minr and cnt<=tne; i--)
            {
                ans[i][j]=cnt;
                cnt++;
            }
            minc++;
        }
        return ans;
    }
};