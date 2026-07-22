class Solution {
   public:
    int solve(int ind, int end, vector<int>& nums, vector<int>& dp) {
        if (ind > end) {
            return 0;
        }
        if (dp[ind] != -1) return dp[ind];
        int take = nums[ind] + solve(ind + 2, end, nums, dp);
        int skip = solve(ind + 1, end, nums, dp);

        return dp[ind] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), -1);

        int ans1 = solve(0, nums.size() - 2, nums, dp);

        fill(dp.begin(), dp.end(), -1);

        int ans2 = solve(1, nums.size() - 1, nums, dp);

        return max(ans1, ans2);
    }
};
