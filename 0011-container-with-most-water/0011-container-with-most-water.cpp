class Solution {
public:
    int maxArea(vector<int>& height) {

        // Left pointer
        int left = 0;

        // Right pointer
        int right = height.size() - 1;

        // Store maximum water
        int maxWater = 0;

        // Continue until both pointers meet
        while (left < right) {

            // Calculate width
            int width = right - left;

            // Find smaller height
            int h = min(height[left], height[right]);

            // Calculate current area
            int area = width * h;

            // Update maximum area
            maxWater = max(maxWater, area);

            // Move the pointer having smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};