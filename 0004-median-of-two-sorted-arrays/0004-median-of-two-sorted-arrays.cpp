class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Store merged elements
        vector<int> ans;

        int i = 0;
        int j = 0;

        // Merge both arrays
        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements of nums1
        while (i < nums1.size()) {
            ans.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements of nums2
        while (j < nums2.size()) {
            ans.push_back(nums2[j]);
            j++;
        }

        int n = ans.size();

        // If total elements are odd
        if (n % 2 == 1)
            return ans[n / 2];

        // If total elements are even
        return (ans[n / 2] + ans[n / 2 - 1]) / 2.0;
    }
};