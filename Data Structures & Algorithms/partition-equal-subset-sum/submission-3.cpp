class Solution {
public:

    int solve(int i, vector<int>& nums, int k, vector<vector<int>>& dp) {

        if (k == 0) {
            return true;
        }

        if (i >= nums.size()) {
            return false;
        }

        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        bool notake = solve(i + 1, nums, k, dp);

        bool take = false;

        if (nums[i] <= k) {
            take = solve(i + 1, nums, k - nums[i], dp);
        }

        return dp[i][k] = take || notake;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int total = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        if (total % 2 != 0) {
            return false;
        }

        int target = total / 2;

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return solve(0, nums, target, dp);
    }
};