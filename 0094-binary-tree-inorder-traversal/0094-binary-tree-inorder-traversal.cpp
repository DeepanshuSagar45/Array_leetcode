class Solution {
public:
    vector<int> result;

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        // Left
        inorder(root->left);

        // Root
        result.push_back(root->val);

        // Right
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return result;
    }
};