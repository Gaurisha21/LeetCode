class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j=0, m=target.size();
        vector<string> ans;
        for(int i=1; i<=n; i++)
        {
            if(target[j]==i)
            {
                ans.push_back("Push");
                j++;
                if(j==m)
                    return ans;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};