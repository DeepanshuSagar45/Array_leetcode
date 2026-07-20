/*----Linear Search-------*/

// its time complexity is O(n)



// class Solution {
// public:
//     int search(vector<int>& nums, int target) {

//         // Traverse the array
//         for (int i = 0; i < nums.size(); i++) {

//             // Target found
//             if (nums[i] == target)
//                 return i;
//         }

//         // Target not found
//         return -1;
//     }
// };

/*-----Modified Binary Search ----------*/


// logic to solve this problem
// Find the middle element.
// One half of the array is always sorted.
// Check whether the target lies in the sorted half.
// Search only that half.

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        // Perform Binary Search
        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Target found
            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[left] <= nums[mid]) {

                // Target lies in left half
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }
                // Search right half
                else {
                    left = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Target lies in right half
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }
                // Search left half
                else {
                    right = mid - 1;
                }
            }
        }

        // Target not found
        return -1;
    }
};