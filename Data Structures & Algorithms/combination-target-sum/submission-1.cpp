class Solution {
   public:
    void findsum(int idx, vector<vector<int>>& ans, vector<int>& arr, int sum, vector<int>& nums,
                 int target) {
        if (sum == target) {
            ans.push_back(arr);
            return;
        }

        // Out of bounds or sum exceeded
        if (idx >= nums.size() || sum > target)
            return; 
        arr.push_back(nums[idx]);
        sum+=nums[idx];
        findsum(idx,ans,arr,sum,nums,target);
        arr.pop_back();
        sum-=nums[idx];
        findsum(idx+1,ans,arr,sum,nums,target);
        }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        findsum(0, ans, arr, 0, nums, target);
        return ans;
    }
};
