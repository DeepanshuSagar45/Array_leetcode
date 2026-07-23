class Solution {
public:
    bool search(vector<int>& nums, int target) {

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Target found
            if (nums[i] == target)
                return true;
        }

        // Target not found
        return false;
    }
};