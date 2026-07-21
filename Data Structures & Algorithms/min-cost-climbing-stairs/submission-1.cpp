
class Solution {
public:
    int solve(int ind,vector<int> cost,vector<int>& dp){
        if(ind >= cost.size()){
            return 0;
        }
        if(dp[ind] != -1)return dp[ind];
        int left = cost[ind] + solve(ind+1,cost,dp);
        int right = cost[ind] + solve(ind+2,cost,dp);
        return dp[ind] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        int val1 = solve(0,cost,dp);
        int val2 = solve(1,cost,dp);
        return min(val1,val2);
    }
};
