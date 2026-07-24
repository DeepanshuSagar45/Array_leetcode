class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> ans;

        int n = nums.size();

        // Check frequency of every element
        for (int i = 0; i < n; i++) {

            // Skip duplicates
            bool alreadyPresent = false;

            for (int x : ans) {
                if (x == nums[i]) {
                    alreadyPresent = true;
                    break;
                }
            }

            if (alreadyPresent)
                continue;

            int count = 0;

            // Count frequency
            for (int j = 0; j < n; j++) {

                if (nums[j] == nums[i])
                    count++;
            }

            // Frequency greater than n/3
            if (count > n / 3)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};