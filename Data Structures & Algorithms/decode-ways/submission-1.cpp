class Solution {
   public:
    bool isValid(int start, int end, string s) {
        if (end >= s.size()) return false;

        string str = s.substr(start, end - start + 1);

        // Leading zero is not allowed
        if (str[0] == '0') return false;

        int num = stoi(str);

        return num >= 1 && num <= 26;
    }
    int solve(int ind, string s,vector<int>& dp) {
        if (ind == s.size()) {
            return 1;
        }
        if(dp[ind] != -1) return dp[ind];
        int ans = 0;
        if (isValid(ind, ind, s)) {
            ans += solve(ind + 1, s,dp);
        }
        if (isValid(ind, ind + 1, s)) {
            ans += solve(ind + 2, s,dp);
        }
        dp[ind] = ans;
        return ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return solve(0,s,dp);
    }
};
