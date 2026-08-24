class Solution {
public:

    // Get maximum subsequence of length k while preserving order
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int remove = nums.size() - k;
        vector<int> st;

        for (int digit : nums) {
            while (!st.empty() && remove > 0 && st.back() < digit) {
                st.pop_back();
                remove--;
            }
            st.push_back(digit);
        }

        st.resize(k);
        return st;
    }

    // Check which remaining sequence is lexicographically larger
    bool greater(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size()) {
            if (a[i] != b[j])
                return a[i] > b[j];

            i++;
            j++;
        }

        return (a.size() - i) > (b.size() - j);
    }

    // Merge two subsequences into the maximum possible sequence
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> result;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (greater(a, i, b, j))
                result.push_back(a[i++]);
            else
                result.push_back(b[j++]);
        }

        return result;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> answer;

        int m = nums1.size();
        int n = nums2.size();

        // i = number of digits taken from nums1
        int start = max(0, k - n);
        int end = min(k, m);

        for (int i = start; i <= end; i++) {
            int j = k - i;

            vector<int> a = maxSubsequence(nums1, i);
            vector<int> b = maxSubsequence(nums2, j);

            vector<int> candidate = merge(a, b);

            if (answer.empty() || greater(candidate, 0, answer, 0))
                answer = candidate;
        }

        return answer;
    }
};