class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        // Assume first triplet is the closest
        int closestSum = nums[0] + nums[1] + nums[2];

        // Check every triplet
        for (int i = 0; i < n - 2; i++) {

            for (int j = i + 1; j < n - 1; j++) {

                for (int k = j + 1; k < n; k++) {

                    int currentSum = nums[i] + nums[j] + nums[k];

                    // Update if current sum is closer
                    if (abs(target - currentSum) < abs(target - closestSum)) {
                        closestSum = currentSum;
                    }
                }
            }
        }

        return closestSum;
    }
};