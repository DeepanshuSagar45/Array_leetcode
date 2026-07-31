class Solution {
public:

    vector<string> ans;

    void solve(string s,
               unordered_set<string>& dict,
               int index,
               string sentence) {

        // Entire string is used
        if (index == s.size()) {

            // Remove last space
            sentence.pop_back();

            ans.push_back(sentence);
            return;
        }

        string word = "";

        // Try every possible word
        for (int i = index; i < s.size(); i++) {

            word += s[i];

            // Word exists in dictionary
            if (dict.count(word)) {

                solve(s,
                      dict,
                      i + 1,
                      sentence + word + " ");
            }
        }
    }

    vector<string> wordBreak(string s,
                             vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(),
                                   wordDict.end());

        solve(s, dict, 0, "");

        return ans;
    }
};