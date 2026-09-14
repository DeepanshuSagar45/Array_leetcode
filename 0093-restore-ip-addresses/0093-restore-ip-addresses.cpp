class Solution {
public:
    vector<string> ans;

    bool valid(string part) {
        // Leading zero is not allowed
        if (part.length() > 1 && part[0] == '0')
            return false;

        // Number must be between 0 and 255
        int num = stoi(part);

        return num >= 0 && num <= 255;
    }

    void solve(string& s, int index, int parts, string current) {

        // Exactly 4 parts
        if (parts == 4) {
            if (index == s.length()) {
                current.pop_back(); // remove last '.'
                ans.push_back(current);
            }
            return;
        }

        // Try 1, 2, or 3 digits
        for (int len = 1; len <= 3; len++) {

            if (index + len > s.length())
                break;

            string part = s.substr(index, len);

            if (!valid(part))
                continue;

            solve(
                s,
                index + len,
                parts + 1,
                current + part + "."
            );
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return ans;
    }
};