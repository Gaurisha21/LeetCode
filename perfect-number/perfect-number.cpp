class Solution {
public:
    bool checkPerfectNumber(int num) {
        int res=0;
        for (int i=1; i*i<=num; ++i) {
            if (num%i==0) {
                res +=i;
                if (i*i!=num) {
                    res += num/i;
                }
            }
        }
        return res-num == num;
    }
};