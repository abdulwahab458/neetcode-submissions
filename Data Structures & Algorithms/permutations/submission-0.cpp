class Solution {
public:
    void helper(vector<int>& nums,vector<bool>& vis,vector<int>& arr, vector<vector<int>>& ans){
        if(arr.size() == nums.size()){
            ans.push_back(arr);
            return;
        }
        for(int i = 0 ; i<nums.size() ; i++){
            if(!vis[i]){
                vis[i]  = true;
                arr.push_back(nums[i]);
                helper(nums,vis,arr,ans);
                arr.pop_back();
                vis[i] =  false; 
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(),false);
        vector<int> arr;
        vector<vector<int>> ans;
        helper(nums,vis,arr,ans);
        return ans;


    }
};
