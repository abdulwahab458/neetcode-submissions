class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mpp;
        map<char, int> mpp2;

        for (auto it : t) {
            mpp[it]++;
        }

        int formed = 0;
        int l = 0;
        int r = 0;
        int len = INT_MAX;
        int start = 0;

        while (r < s.size()) {

            mpp2[s[r]]++;

            if (mpp.find(s[r]) != mpp.end() &&
                mpp[s[r]] == mpp2[s[r]]) {
                formed++;
            }

            while (formed == mpp.size()) {

                if (r - l + 1 < len) {
                    len = r - l + 1;
                    start = l;
                }

                mpp2[s[l]]--;

                if (mpp.find(s[l]) != mpp.end() &&
                    mpp2[s[l]] < mpp[s[l]]) {
                    formed--;
                }

                l++;
            }

            r++;
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};