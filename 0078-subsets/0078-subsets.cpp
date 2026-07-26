class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;

        int n = nums.size();

        // Total subsets = 2^n
        int total = 1 << n;

        // Generate every subset
        for (int mask = 0; mask < total; mask++) {

            vector<int> subset;

            // Check every bit
            for (int i = 0; i < n; i++) {

                // If ith bit is set, include nums[i]
                if (mask & (1 << i))
                    subset.push_back(nums[i]);
            }

            ans.push_back(subset);
        }

        return ans;
    }
};