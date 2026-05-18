class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> mpp;
        for (int i = 0; i < s1.size(); i++) {
            mpp[s1[i]]++;
        }
        int l = 0;
        int r = 0;
        while (r < s2.size()) {
            if (mpp.find(s2[r]) != mpp.end()) {
                mpp[s2[r]]--;
            }
            while (r - l + 1 > s1.size()) {
                if (mpp.find(s2[l]) != mpp.end()) {
                    mpp[s2[l]]++;
                }
                l++;
            }
            int flag = 0;
            for (auto it : mpp) {
                if (it.second != 0) flag = 1;
            }
            if (flag == 0) return true;

            r++;
        }

        return false;
        ;
    }
};
