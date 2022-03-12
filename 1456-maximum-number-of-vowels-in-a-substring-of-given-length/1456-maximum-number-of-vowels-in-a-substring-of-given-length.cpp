class Solution {
public:
    bool isVowel(char a)
    {
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u') return true;
        return false;
    }
    int maxVowels(string str, int k) {
        int s=0, e=0, n=str.length(), vow=0, mx=INT_MIN, count=0;
        while(e<n)
        {
            if(isVowel(str[e++])) vow++;
            mx=max(mx,vow);
            count++;
            while(count==k)
            {
                if(isVowel(str[s++]))
                    vow--;
                count--;
            }
        }
        return mx;
    }
};