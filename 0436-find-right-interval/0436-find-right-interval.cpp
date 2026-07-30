class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<int> ans(n, -1);

        // Check every interval
        for (int i = 0; i < n; i++) {

            int minStart = INT_MAX;

            // Compare with every other interval
            for (int j = 0; j < n; j++) {

                // Valid right interval
                if (intervals[j][0] >= intervals[i][1]) {

                    // Keep the smallest valid start
                    if (intervals[j][0] < minStart) {

                        minStart = intervals[j][0];
                        ans[i] = j;
                    }
                }
            }
        }

        return ans;
    }
};