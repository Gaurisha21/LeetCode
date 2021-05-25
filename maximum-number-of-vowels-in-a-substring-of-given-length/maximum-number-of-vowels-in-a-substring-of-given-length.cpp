class Solution {
public:
    bool isVowel(char ch)
    {
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {
        int s1=0, e=0, count=0, maxC=0, n=s.length();
        while(e<n)
        {
            if(isVowel(s[e++])) count++;
            if(e-s1==k)
            {
                maxC=max(maxC, count);
                if(isVowel(s[s1++])) count--;
            }
        }
        return maxC;
    }
};