class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int> candy(candies);
        vector<bool> ans;
        sort(candy.begin(), candy.end());
        for(auto it = candies.begin(); it != candies.end(); it++)
        {
            bool a;
            int i = *it, n = candies.size()-1;
            int last = candy[n];
            int x = i + extraCandies;
            if(x >= last)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
        
    }
};