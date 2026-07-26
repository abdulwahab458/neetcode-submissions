class Solution {
public:
    int start = 0;
    int maxLen = 1;

    void odd(int left, int right, string &s) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        int len = right - left - 1;

        if (len > maxLen) {
            maxLen = len;
            start = left + 1;
        }
    }

    void even(int left, int right, string &s) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        int len = right - left - 1;

        if (len > maxLen) {
            maxLen = len;
            start = left + 1;
        }
    }

    void solve(int i, string &s) {
        if (i >= s.size())
            return;

        // Odd length palindrome
        odd(i - 1, i + 1, s);

        // Even length palindrome
        even(i, i + 1, s);

        solve(i + 1, s);
    }

    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        solve(0, s);

        return s.substr(start, maxLen);
    }
};