class Solution {
public:
    bool isPal(string str)
    {
        int s=0, e=str.length()-1;
        while(s<=e)
            if(str[s++]!=str[e--])
                return false;
        return true;
    }
    int removePalindromeSub(string s) {
        if(isPal(s))
            return 1;
        return 2;
    }
};