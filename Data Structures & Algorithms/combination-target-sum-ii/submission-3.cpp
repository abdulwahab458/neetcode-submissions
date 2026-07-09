class Solution {
   public:
    void helper(int idx, int target, vector<int>& candidates, vector<vector<int>>& ans,
                vector<int>& arr) {
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        for(int i = idx ; i<candidates.size() ; i++){
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            arr.push_back(candidates[i]);
            helper(i+1,target-candidates[i],candidates,ans,arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> arr;
        helper(0, target,candidates, ans, arr);
        return ans;
    }
};
