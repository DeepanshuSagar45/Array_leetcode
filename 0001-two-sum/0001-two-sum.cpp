// // // // class Solution {
// // // // public:
// // // //     vector<int> twoSum(vector<int>& nums, int target) {

// // // //         // Get the size of the array
// // // //         int n = nums.size();

// // // //         // Check every possible pair
// // // //         for (int i = 0; i < n; i++) {

// // // //             // Start from the next element
// // // //             for (int j = i + 1; j < n; j++) {

// // // //                 // If the sum matches the target
// // // //                 if (nums[i] + nums[j] == target) {

// // // //                     // Return the indices
// // // //                     return {i, j};
// // // //                 }
// // // //             }
// // // //         }

// // // //         // No solution found (not needed for LeetCode because one solution is guaranteed)
// // // //         return {};
// // // //     }
// // // // };
// // // class Solution {
// // // public:
// // //     vector<int> twoSum(vector<int>& nums, int target) {

// // //         // Hash map stores:
// // //         // Key   -> Array value
// // //         // Value -> Index of that value
// // //         unordered_map<int, int> mp;

// // //         // Traverse the array
// // //         for (int i = 0; i < nums.size(); i++) {

// // //             // Find the number required to make the target
// // //             int complement = target - nums[i];

// // //             // Check whether the complement already exists
// // //             if (mp.find(complement) != mp.end()) {

// // //                 // Return indices of complement and current element
// // //                 return {mp[complement], i};
// // //             }

// // //             // Store current number and its index
// // //             mp[nums[i]] = i;
// // //         }

// // //         // No solution found
// // //         return {};
// // //     }
// // // };
// // class Solution {
// // public:
// //     vector<int> twoSum(vector<int>& nums, int target) {

// //         // Store value with its original index
// //         vector<pair<int, int>> arr;

// //         for (int i = 0; i < nums.size(); i++) {
// //             arr.push_back({nums[i], i});
// //         }

// //         // Sort according to value
// //         sort(arr.begin(), arr.end());

// //         // Two pointers
// //         int left = 0;
// //         int right = arr.size() - 1;

// //         while (left < right) {

// //             int sum = arr[left].first + arr[right].first;

// //             // Target found
// //             if (sum == target) {
// //                 return {arr[left].second, arr[right].second};
// //             }

// //             // Increase sum
// //             else if (sum < target) {
// //                 left++;
// //             }

// //             // Decrease sum
// //             else {
// //                 right--;
// //             }
// //         }

// //         return {};
// //     }
// // };
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {

//         // Store value and original index
//         vector<pair<int, int>> arr;

//         for (int i = 0; i < nums.size(); i++) {
//             arr.push_back({nums[i], i});
//         }

//         // Sort the array
//         sort(arr.begin(), arr.end());

//         // Traverse every element
//         for (int i = 0; i < arr.size(); i++) {

//             // Number needed to reach target
//             int need = target - arr[i].first;

//             int low = i + 1;
//             int high = arr.size() - 1;

//             // Binary Search
//             while (low <= high) {

//                 int mid = low + (high - low) / 2;

//                 if (arr[mid].first == need) {
//                     return {arr[i].second, arr[mid].second};
//                 }

//                 else if (arr[mid].first < need) {
//                     low = mid + 1;
//                 }

//                 else {
//                     high = mid - 1;
//                 }
//             }
//         }

//         return {};
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Find required number
            int need = target - nums[i];

            // Check if it exists in the hash map
            if (mp.count(need)) {
                return {mp[need], i};
            }

            // Store current value and index
            mp[nums[i]] = i;
        }

        return {};
    }
};