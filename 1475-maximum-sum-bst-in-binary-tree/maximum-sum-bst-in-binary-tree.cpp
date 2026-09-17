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

 class info{
    public :
        int sum;
        int maxval;
        int minval;

        info(int sum, int maxval, int minval) //constructor
        {
            this->sum=sum;
            this->maxval=maxval;
            this->minval=minval;
        }
 };
class Solution {
public:
    int maxsum=0;
    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxsum;
    }

    info solve(TreeNode* root){
        // empty tree
        if(root==nullptr)
            return info(0, INT_MIN, INT_MAX);
        
        //leaf node
        if(root->left == nullptr && root->right==nullptr)
            return info(root->val, root->val, root->val);

        // post order dfs...
        info left=solve(root->left); //L
        info right=solve(root->right); //R

        // current tree is a bst??
        if(root->val>left.maxval && root->val<right.minval) {
            int s=root->val + left.sum + right.sum;
            maxsum=max(maxsum,s); //update maxsum
            int mx=max(root->val,right.maxval);
            int mn=min(root->val,left.minval);
            return info(s,mx,mn); //return triplet in node form
        }
        else {
            int s=max(left.sum,right.sum);
            maxsum=max(maxsum,s);
            //mark tis subtree as invalid bst
            int mx=INT_MAX;
            int mn=INT_MIN;
            return info(s,mx,mn);
        }
    }
};