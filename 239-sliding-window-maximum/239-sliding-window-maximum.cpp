class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> deque;
        int n = nums.size(), idx = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            while (deque.size() != 0 && deque.front() <= i - k)
                deque.pop_front();

            while (deque.size() != 0 && nums[deque.back()] <= nums[i])
                deque.pop_back();

            deque.push_back(i);

            if (i >= k - 1)
                ans.push_back(nums[deque.front()]);
        }
        return ans;
    }
};