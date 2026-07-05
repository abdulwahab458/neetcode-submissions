class Solution {
public:
    void findsubsets(int idx,vector<int> nums,vector<vector<int>>& ans,vector<int>& arr){
        if(idx >= nums.size()){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[idx]);
        findsubsets(idx+1,nums,ans,arr);
        arr.pop_back();                                                                                     
        findsubsets(idx+1,nums,ans,arr);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        findsubsets(0,nums,ans,arr);
        return ans;
    }
};
