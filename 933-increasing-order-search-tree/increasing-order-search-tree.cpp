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
    void inorder(TreeNode* root, vector<int> &nums) {
        if(root==NULL) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        TreeNode* dummy=new TreeNode(0);
        TreeNode* curr=dummy;
        for(int val: nums) {
            TreeNode* node=new TreeNode(val);
            node->left=node->right=NULL;
            curr->right=node;
            curr=node;
        }
        return dummy->right;
    }
}; 