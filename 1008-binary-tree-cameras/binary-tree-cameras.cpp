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
    int dfs(TreeNode* root, int& camera){
        if(root==NULL){
            return 1;
        }
        int left=dfs(root->left,camera);
        int right=dfs(root->right,camera);
        if(left==-1 || right==-1){
            camera++;
            return 0;
        }
        else if(left==1 && right==1){
            return -1;
        }
        else{
            return 1;
        }
    }
    int minCameraCover(TreeNode* root) {
        int camcount=0;
        if(dfs(root,camcount)==-1){
            camcount++;
            
        }
        return camcount;
    }
};