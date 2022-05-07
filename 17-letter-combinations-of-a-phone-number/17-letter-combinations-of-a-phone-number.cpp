class Solution {
public:
    int letterCombinations(string digits, string &str, vector<string> &ans, int idx, vector<string> chrs)
    {
        if(idx==digits.size())
        {
            ans.push_back(str);
            return 1;
        }
        int count=0;
        int num=digits[idx]-'0';
        string chars = chrs[num-2];
        int l=chars.length();
        for(int i=0; i<l; i++)
        {
            string p=str+chars[i];
            count+=letterCombinations(digits,p,ans,idx+1,chrs);
        }
        return count;
    }
        
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return {};
        vector<string> ans, chrs={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string str="";
        int a=letterCombinations(digits,str,ans,0,chrs);
        return ans;
    }
};