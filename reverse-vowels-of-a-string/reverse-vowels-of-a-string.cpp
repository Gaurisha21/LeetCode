class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size();
        while(i<j){
            if((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'|| s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')&&(s[j]=='a'|| s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'|| s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U')){
                swap(s[i++],s[j--]);
            }
            if(!(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'|| s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'))
                i++;
            if(!(s[j]=='a'|| s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'|| s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U'))
                j--;
        }
        return s;
    }
};