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
    // vector<int> ans;
    // int prev = 0;
    // int currCount = 0;
    // int maxCount = 0;
    // bool first = true;
    map<int,int> mp;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        mp[root->val]++;

        // if (first || root->val != prev) {
        //     currCount = 1;
        //     first = false;
        // } else {
        //     currCount++;
        // }

        // if (currCount > maxCount) {
        //     maxCount = currCount;
        //     ans.clear();
        //     ans.push_back(root->val);
        // } else if (currCount == maxCount) {
        //     ans.push_back(root->val);
        // }

        // prev = root->val;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);

        vector<int> ans;
        int maxCount = 0;

        for (auto p : mp) {
            if (p.second > maxCount) {
                maxCount = p.second;
                ans.clear();
                ans.push_back(p.first);
            }
            else if (p.second == maxCount) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};