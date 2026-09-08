class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int start, vector<int>& current) {

        // Add current subset
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicates at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Choose
            current.push_back(nums[i]);

            solve(nums, i + 1, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Important: sort so duplicate elements are together
        sort(nums.begin(), nums.end());

        vector<int> current;

        solve(nums, 0, current);

        return result;
    }
};