class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        int n = nums.size();

        if (n == 0)
            return ans;

        int start = nums[0];

        for (int i = 1; i <= n; i++) {

            // End of a consecutive range
            if (i == n || (long long)nums[i] != (long long)nums[i - 1] + 1) {

                // Single number
                if (start == nums[i - 1]) {
                    ans.push_back(to_string(start));
                }
                // Range
                else {
                    ans.push_back(
                        to_string(start) + "->" + to_string(nums[i - 1])
                    );
                }

                // Start the next range
                if (i < n) {
                    start = nums[i];
                }
            }
        }

        return ans;
    }
};