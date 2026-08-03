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
    void dfs(TreeNode* root, int cs,int &root_to_leaf) {
        if(root == NULL)
            return ;
        cs=cs*10+root->val;
        if(root->left == NULL && root->right == NULL)
            root_to_leaf += cs;
        dfs(root->left, cs, root_to_leaf);
        dfs(root->right, cs, root_to_leaf);
    }

    int sumNumbers(TreeNode* root) {
        int root_to_leaf = 0;
        dfs(root, 0, root_to_leaf);
        return root_to_leaf;
    }
};