class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mpp;
        for(auto& it:nums){
            mpp[it]++;
        }
        int ans = 0 ;
        for(auto it:mpp){
            if(it.second>1){
                ans = it.first;
            }
        }
        return ans;
    }
};
