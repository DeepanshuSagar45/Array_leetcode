class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        unordered_set<int> seen;

        return dfs(root, k, seen);
    }

    bool dfs(TreeNode* root, int k, unordered_set<int>& seen) {
        
        if (root == nullptr)
            return false;

        // Check if the required value already exists
        if (seen.count(k - root->val))
            return true;

        // Store current value
        seen.insert(root->val);

        // Search left and right
        return dfs(root->left, k, seen) ||
               dfs(root->right, k, seen);
    }
};