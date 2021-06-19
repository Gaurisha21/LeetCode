class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++)
        {
            int a=i, count=0;
            while(a!=0)
            {
                count++;
                a&=(a-1);
            }
            ans.push_back(count);
        }
        return ans;
    }
};