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
    void inorder(TreeNode* root, vector<int>& nums) {
        if(root==nullptr){
            return;
        }
        inorder(root->left ,nums); //left
        nums.push_back(root->val); //node
        inorder(root->right,nums); //right
    }

    vector<int> find_xy(vector<int> nums){
        int n=nums.size();
        int x=-1, y=-1;
        bool flag=false;
        for(int i=0;i<n-1; i++) {
            if(nums[i+1] < nums[i]) {
                y=nums[i+1];  //update y
                if(flag==0){
                    //the first swap occurrence
                    x=nums[i];
                    flag=true;
                }
                else{
                    //find second swap occurence
                    break;
                }
            }
        }
        return vector<int>{x,y};
    }
    void recover(TreeNode* root, int count, int x, int y) {
       if(root!=nullptr) {
        if(root->val == x || root-> val==y){
            root->val= root->val==x?y:x;
            if(--count==0){
                return ;
            }
        }
            recover(root->left, count, x,y);
            recover(root->right, count, x,y);
        }
       
    }

    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        vector<int> swapped=find_xy(nums);
        recover(root,2,swapped[0],swapped[1]);
    }
};