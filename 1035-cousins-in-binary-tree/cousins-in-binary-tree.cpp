/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* x_parent = NULL;
    TreeNode* y_parent = NULL;

    int x_depth = -1;
    int y_depth = -1;

public:
    void dfs(TreeNode* root, TreeNode* parent, int depth, int x, int y) {
        if (root == NULL) {
            return;
        }

        if (root->val == x) {
            x_parent = parent;
            x_depth = depth;
        }

        if (root->val == y) {
            y_parent = parent;
            y_depth = depth;
        }

        dfs(root->left, root, depth + 1, x, y);
        dfs(root->right, root, depth + 1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, 0, x, y);

        return x_depth == y_depth && x_parent != y_parent;
    }
};