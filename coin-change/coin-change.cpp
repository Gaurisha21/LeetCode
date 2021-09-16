class Solution {
public:
    int coinChange(vector<int>& arr, int Tar) {
        if(Tar==0) return 0;
        vector<long> dp(Tar+1,(int) 1e9);
        dp[0] = 0;
        for (int tar = 1; tar <= Tar; tar++) {
            for (int ele : arr) {
                if (tar - ele >= 0)
                    dp[tar] = min(dp[tar - ele] + 1, dp[tar]);
            }
        }
        return dp[Tar] != (int) 1e9 ? dp[Tar] : -1;
    }
};