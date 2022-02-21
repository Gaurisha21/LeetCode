class Solution {
public:
    int digStr(int idx, string digits, vector<string> &ans, string str, vector<string> let)
    {
        if(idx==digits.length())
        {
            ans.push_back(str);
            return 1;
        }
        int count=0;
        int l = ((digits[idx]-'0')-2);
        for(int i=0; i<let[l].length(); i++)
        {
            string p = str+let[l][i];
            count+=digStr(idx+1,digits,ans,p,let);
        }
        return count;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        vector<string> ans;
        string str="";
        vector<string> let{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int a = digStr(0,digits,ans,str,let);
        return ans;
    }
};