class Solution {
public:
    void helper(int idx,vector<int>& nums,vector<vector<int>>& ans,vector<int>& arr){
        ans.push_back(arr);
        for(int i = idx ; i<nums.size() ; i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
                arr.push_back(nums[i]);
                helper(i+1,nums,ans,arr);
                arr.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> arr;
        helper(0,nums,ans,arr);
        return ans;
    }
};
