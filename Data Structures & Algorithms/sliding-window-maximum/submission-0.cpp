class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ans;

        int l = 0;
        int r = 0;

        while (r < nums.size()) {

            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);

            // remove out of window indices
            if (dq.front() < l) {
                dq.pop_front();
            }

            // window size reached
            if (r - l + 1 == k) {

                ans.push_back(nums[dq.front()]);

                l++;
            }

            r++;
        }

        return ans;
    }
};