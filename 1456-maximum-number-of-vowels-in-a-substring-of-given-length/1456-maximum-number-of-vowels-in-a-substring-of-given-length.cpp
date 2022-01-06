class Solution {
public:
    bool isVow(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            return true;
        return false;
    }
    int maxVowels(string str, int k) {
        int s=0,e=0,count=0,vow=0,maxVow=INT_MIN,n=str.length();
        while(e<n)
        {
            if(isVow(str[e++]))
                vow++;
            count++;
            while(count==k)
            {
                maxVow = max(maxVow,vow);
                if(isVow(str[s++]))
                    vow--;
                count--;
            }
        }
        return maxVow;
    }
};