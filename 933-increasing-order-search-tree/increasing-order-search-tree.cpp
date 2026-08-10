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

TreeNode* curr;
    void inorder(TreeNode* root) {
        if(root==NULL) return; //base case
        inorder(root->left); //left recursion
        root->left=nullptr; //re-linking
        curr->right=root;
        curr=root;
        inorder(root->right); //right recursion
    }
    public:
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode* dummy=new TreeNode(0);
        
        curr=dummy;
        inorder(root);
       
        return dummy->right;
    }
}; 