class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        stringstream ss(path);
        string part;

        // Split path using '/'
        while (getline(ss, part, '/')) {

            // Current directory or empty part
            if (part == "" || part == ".") {
                continue;
            }

            // Parent directory
            else if (part == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }

            // Normal directory/file name
            else {
                st.push(part);
            }
        }

        // Build the canonical path
        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        // If stack was empty
        if (ans.empty()) {
            return "/";
        }

        return ans;
    }
};