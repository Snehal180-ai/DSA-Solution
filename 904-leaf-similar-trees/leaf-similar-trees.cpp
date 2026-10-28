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
public:
    void dfs(TreeNode* root, vector<int>& leaves) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
            return;
        }

        dfs(root->left, leaves);
        dfs(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;

        dfs(root1, leaf1);
        dfs(root2, leaf2);

        return leaf1 == leaf2;
    }
};