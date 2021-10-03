class Solution {
int LPS(string &s,int i,int j,vector<vector<int>> &dp){

    if(i>j)
        return 0;
    
    if(i==j)
        return 1;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(s[i]==s[j]){
        return dp[i][j]=LPS(s,i+1,j-1,dp)+2;
    }
    
    else {
        return dp[i][j]=max(LPS(s,i+1,j,dp),LPS(s,i,j-1,dp));
    }
}
public:
int longestPalindromeSubseq(string s) {

    vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
   return LPS(s,0,s.size()-1,dp);
}
};