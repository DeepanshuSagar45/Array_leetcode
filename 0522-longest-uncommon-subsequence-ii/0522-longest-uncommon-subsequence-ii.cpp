class Solution {
public:
    bool isSubsequence(string a, string b) {
        int i = 0, j = 0;

        while (i < a.length() && j < b.length()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }

        return i == a.length();
    }

    int findLUSlength(vector<string>& strs) {
        int ans = -1;

        for (int i = 0; i < strs.size(); i++) {
            bool uncommon = true;

            for (int j = 0; j < strs.size(); j++) {
                if (i == j)
                    continue;

                // If strs[i] is a subsequence of another string,
                // it is not uncommon.
                if (isSubsequence(strs[i], strs[j])) {
                    uncommon = false;
                    break;
                }
            }

            if (uncommon) {
                ans = max(ans, (int)strs[i].length());
            }
        }

        return ans;
    }
};