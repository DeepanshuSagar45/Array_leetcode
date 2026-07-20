// //Shifting Elements
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {

//         int n = nums.size();

//         // Traverse the array
//         for (int i = 0; i < n; i++) {

//             // If current element equals val
//             if (nums[i] == val) {

//                 // Shift all elements to the left
//                 for (int j = i; j < n - 1; j++) {
//                     nums[j] = nums[j + 1];
//                 }

//                 // Reduce the effective size
//                 n--;

//                 // Check the current index again
//                 i--;
//             }
//         }

//         return n;
//     }
// };

/*---- second approach------*/
//Two Pointers
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // Pointer for placing valid elements
        int k = 0;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Keep elements not equal to val
            if (nums[i] != val) {

                nums[k] = nums[i];
                k++;
            }
        }

        // Number of valid elements
        return k;
    }
};