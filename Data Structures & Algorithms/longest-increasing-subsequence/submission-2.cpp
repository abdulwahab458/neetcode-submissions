class Solution {
   public:
    int solve(int i, int j, vector<int>& nums,vector<vector<int>> &dp) {
        if (i >= nums.size()) {
            return 0;
        }
        if(dp[i][j+1] != -1) return dp[i][j+1];
        int nopick = solve(i + 1, j, nums,dp);
        int pick = 0;
        if (j == -1 || nums[i] > nums[j]) {
            pick = 1 + solve(i + 1, i, nums,dp);
        }
        return dp[i][j+1] =  max(pick, nopick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        vector<int> arr;
        return solve(0, -1, nums,dp);
    }
};