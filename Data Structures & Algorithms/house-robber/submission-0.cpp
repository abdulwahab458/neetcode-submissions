class Solution {
public:
    int solve(int ind,vector<int> nums,vector<int>& dp){
        if(ind >= nums.size()){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int val1 = nums[ind] + solve(ind+2,nums,dp);
        int val2 = solve(ind+1,nums,dp);
        return dp[ind] = max(val1,val2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(0,nums,dp);
    }
};
