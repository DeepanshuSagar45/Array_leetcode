class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // If array is empty
        if (strs.empty())
            return "";

        // Assume first string is the common prefix
        string prefix = strs[0];

        // Compare with remaining strings
        for (int i = 1; i < strs.size(); i++) {

            // Keep reducing prefix until it matches
            while (strs[i].find(prefix) != 0) {

                // Remove last character
                prefix.pop_back();

                // No common prefix exists
                if (prefix.empty())
                    return "";
            }
        }

        return prefix;
    }
};