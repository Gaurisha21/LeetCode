class Solution {
public:
    int maximum69Number (int num) {
        string ss= to_string(num);
        for(int i=0;i<ss.length();i++)
        {
            if(ss[i]=='6')
            {
                ss[i]='9';
                break;
            }
        }
       return stoi(ss);
    }
};