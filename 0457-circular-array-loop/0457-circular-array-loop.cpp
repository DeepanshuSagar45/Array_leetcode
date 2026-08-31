class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();

        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int slow = i;
            int fast = i;

            // Direction of the starting element
            bool direction = nums[i] > 0;

            while (true) {

                // Next index must have the same direction
                int nextSlow = nextIndex(nums, slow);

                if ((nums[nextSlow] > 0) != direction)
                    break;

                // Fast pointer: first move
                int nextFast = nextIndex(nums, fast);

                if ((nums[nextFast] > 0) != direction)
                    break;

                // Fast pointer: second move
                nextFast = nextIndex(nums, nextFast);

                if ((nums[nextFast] > 0) != direction)
                    break;

                slow = nextSlow;
                fast = nextFast;

                // Cycle found
                if (slow == fast) {

                    // One-element cycle is not valid
                    if (slow == nextIndex(nums, slow))
                        break;

                    return true;
                }
            }
        }

        return false;
    }
};