class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;

        for (int num : nums) {
            // Keep the number if:
            // fewer than 2 elements are stored, OR
            // current number is different from nums[k - 2]
            if (k < 2 || num != nums[k - 2]) {
                nums[k] = num;
                k++;
            }
        }

        return k;
    }
};