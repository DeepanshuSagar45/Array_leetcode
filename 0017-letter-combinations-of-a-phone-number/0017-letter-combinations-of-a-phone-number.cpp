class Solution {
public:
    vector<string> ans;

    vector<string> keypad = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void solve(string& digits, int index, string current) {

        // All digits processed
        if (index == digits.length()) {
            ans.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        for (char c : keypad[digit]) {
            current.push_back(c);

            solve(digits, index + 1, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        solve(digits, 0, "");

        return ans;
    }
};