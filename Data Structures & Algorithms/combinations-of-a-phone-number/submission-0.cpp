class Solution {
   public:
    void helper(int idx, vector<string>& ans, vector<string> keypad, string& curr, string digits) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }
        string temp = keypad[digits[idx] - '0'];

        for (int i = 0; i < temp.size(); i++) {
            curr += temp[i];
            helper(idx + 1, ans, keypad, curr, digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> keypad = {
            "",      // 0
            "",      // 1
            "abc",   // 2
            "def",   // 3
            "ghi",   // 4
            "jkl",   // 5
            "mno",   // 6
            "pqrs",  // 7
            "tuv",   // 8
            "wxyz"   // 9
        };
        vector<string> ans;
        string curr = "";
        if (digits.empty()) return {};
        helper(0, ans, keypad, curr, digits);
        return ans;
    }
};
