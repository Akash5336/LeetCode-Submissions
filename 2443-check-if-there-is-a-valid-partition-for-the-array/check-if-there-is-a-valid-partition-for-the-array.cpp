class Solution {
public:
 bool check(vector<int> &nums, vector<int> &dp, int i)
    {
        int n = nums.size();
        if (i == nums.size())
            return true;
        if (dp[i] != -1)
            return dp[i];

        if (i + 1 < n && nums[i] == nums[i + 1])
        {
            if (check(nums, dp, i + 2))
                return dp[i] = true;
        }

        if (i + 2 < n && nums[i] == nums[i + 2] and nums[i] == nums[i + 1])
        {
            if (check(nums, dp, i + 3))
                return dp[i] = true;
        }
        if (i + 2 < n && nums[i] + 1 == nums[i + 1] && nums[i] + 2 == nums[i + 2])
        {
            if (check(nums, dp, i + 3))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return check(nums, dp, 0);
    }
};