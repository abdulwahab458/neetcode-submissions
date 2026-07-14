class Solution {
   public:
    void helper(int idx, string s, vector<vector<string>>& ans, vector<string>& str) {
        if (idx == s.size()) {
            ans.push_back(str);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s.substr(idx, i - idx + 1))) {
                str.push_back(s.substr(idx, i - idx + 1)) ;
                helper(i + 1,s, ans, str);
                str.pop_back();
            }
        }
    }
    bool isPalindrome(string str) {
        int left = 0;
        int right = str.size() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> str;
        helper(0, s, ans, str);
        return ans;
    }
};
