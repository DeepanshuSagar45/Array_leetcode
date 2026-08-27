class Solution {
public:
    unordered_map<int, int> pos;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int left, int right) {

        if (left > right)
            return nullptr;

        // Last element in postorder is the root
        int rootValue = postorder[postIndex--];

        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int index = pos[rootValue];

        // Build RIGHT first
        root->right = build(inorder, postorder, index + 1, right);

        // Then build LEFT
        root->left = build(inorder, postorder, left, index - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        postIndex = postorder.size() - 1;

        // Store positions of elements in inorder
        for (int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};