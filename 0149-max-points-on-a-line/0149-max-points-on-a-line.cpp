class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int n = points.size();

        // If there are 2 or fewer points
        if (n <= 2)
            return n;

        int maxCount = 2;

        // Select first point
        for (int i = 0; i < n; i++) {

            // Select second point
            for (int j = i + 1; j < n; j++) {

                int count = 2;

                // Check every remaining point
                for (int k = 0; k < n; k++) {

                    if (k == i || k == j)
                        continue;

                    long long x1 = points[i][0];
                    long long y1 = points[i][1];

                    long long x2 = points[j][0];
                    long long y2 = points[j][1];

                    long long x3 = points[k][0];
                    long long y3 = points[k][1];

                    // Check if three points are on same line
                    if ((x2 - x1) * (y3 - y1) ==
                        (y2 - y1) * (x3 - x1)) {

                        count++;
                    }
                }

                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};